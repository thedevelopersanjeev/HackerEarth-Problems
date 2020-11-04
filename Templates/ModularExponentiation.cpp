
// (x ^ y) in O(log(n)) time
int binpow(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
        }
        x *= x;
        y >>= 1;
    }
    return ans;
}

// (x ^ y) % mod in O(log(n)) time
int modpow(int x, int y, int mod) {
    x %= mod;
    int ans = 1;
    while (y > 0) {
        if (y & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}