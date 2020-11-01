#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&...args) {
    ((cout << args), ...);
}

void solve(int tc) {
    int N, K;
    read(N, K);
    vector<int> A(N);
    for (auto &ele : A) read(ele);
    vector<int> cnt(50);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 50; j++) {
            if (A[i] >> j & 1) cnt[j]++;
        }
    }
    int x = 0;
    for (int i = 49; i >= 0; i--) {
        if (x + (1 << i) > K) continue;
        if (cnt[i] * 2 < N) x += (1LL << i);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += x ^ A[i];
    }
    write(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}