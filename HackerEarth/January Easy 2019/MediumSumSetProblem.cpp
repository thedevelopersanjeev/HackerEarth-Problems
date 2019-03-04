#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
 
inline int mod_add(int a, int b, int m = MOD) {
    int sum = a + b;
    return sum >= m ? sum - m : sum;
}
 
inline int mod_sub(int a, int b, int m = MOD) {
    int diff = a - b;
    return diff < 0 ? diff + m : diff;
}
 
inline unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
    return x % m;
#endif
    // Optimized mod for Codeforces 32-bit machines.
    // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
    unsigned x_high = x >> 32, x_low = (unsigned) x;
    unsigned quot, rem;
    assert(x_high < m);
    asm("divl %4\n"
        : "=a" (quot), "=d" (rem)
        : "d" (x_high), "a" (x_low), "r" (m));
    return rem;
}
 
inline int mod_mul(int a, int b, int m = MOD) {
    return fast_mod((uint64_t) a * b, m);
}
 
inline int mod_pow(int a, long long p, int m = MOD) {
    assert(p >= 0);
    int result = 1;
 
    while (p > 0) {
        if (p & 1)
            result = mod_mul(result, a, m);
 
        a = mod_mul(a, a, m);
        p >>= 1;
    }
 
    return result;
}
 
inline int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;
 
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
 
    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}
 
namespace NTT {
    vector<int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    int root;
 
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }
 
    int round_up_power_two(int n) {
        assert(n > 0);
 
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;
 
        return n;
    }
 
    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }
 
    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<int> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);
 
            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }
 
        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }
 
    void find_root() {
        int order = MOD - 1;
        max_size = 1;
 
        while (order % 2 == 0) {
            order /= 2;
            max_size *= 2;
        }
 
        root = 2;
 
        // Find a max_size-th primitive root of MOD.
        while (!(mod_pow(root, max_size) == 1 && mod_pow(root, max_size / 2) != 1))
            root++;
    }
 
    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();
 
        assert(n <= max_size);
 
        if ((int) roots.size() >= n)
            return;
 
        int length = get_length(roots.size());
        roots.resize(n);
 
        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            int z = mod_pow(root, max_size >> (length + 1));
 
            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = mod_mul(roots[i], z);
            }
 
            length++;
        }
    }
 
    void fft_iterative(int N, vector<int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);
 
        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    int even = values[start + i];
                    int odd = mod_mul(values[start + n + i], roots[n + i]);
                    values[start + n + i] = mod_sub(even, odd);
                    values[start + i] = mod_add(even, odd);
                }
    }
 
    const int FFT_CUTOFF = 150;
 
    vector<int> mod_multiply(vector<int> left, vector<int> right) {
        int n = left.size();
        int m = right.size();
 
        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < MOD);
 
        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < MOD);
 
        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1);
 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];
 
                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }
 
            for (int i = 0; i < (int) result.size(); i++)
                if (result[i] >= (uint64_t) MOD)
                    result[i] %= MOD;
 
            return vector<int>(result.begin(), result.end());
        }
 
        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);
 
        bool equal = left == right;
        fft_iterative(N, left);
 
        if (equal)
            right = left;
        else
            fft_iterative(N, right);
 
        int inv_N = mod_inv(N);
 
        for (int i = 0; i < N; i++)
            left[i] = mod_mul(mod_mul(left[i], right[i]), inv_N);
 
        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }
 
    vector<int> mod_power(const vector<int> &v, int exponent) {
        assert(exponent >= 0);
        vector<int> result = {1};
 
        if (exponent == 0)
            return result;
 
        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);
 
            if (exponent & 1 << k)
                result = mod_multiply(result, v);
        }
 
        return result;
    }
}
 
 
const int MAX = 5e5 + 5;
 
int N, M;
vector<int> A(MAX, 0), C(MAX, 0);
 
int main() {
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        A[x] = 1;
    }
 
    scanf("%d", &M);
 
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        C[x] = 1;
    }
 
    assert(N <= M);
    reverse(C.begin(), C.end());
    vector<int> product = NTT::mod_multiply(A, C);
    vector<int> output;
 
    for (int shift = 1; shift < MAX; shift++)
        if (product[MAX - 1 - shift] == N)
            output.push_back(shift);
 
    for (int i = 0; i < (int) output.size(); i++)
        printf("%d%c", output[i], i < (int) output.size() - 1 ? ' ' : '\n');
}