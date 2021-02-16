#include <bits/stdc++.h>
using namespace std;

// computes x ^ y
int binpow(int x, int y) {
    int ans = 1LL;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = ans * x;
        }
        x = x * x;
        y = y / 2;
    }
    return ans;
}

// computes (x ^ y) % z
int binpow(int x, int y, int z) {
    x = x % z;
    int ans = 1LL;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % z;
        }
        x = (x * x) % z;
        y = y / 2;
    }
    return ans;
}
