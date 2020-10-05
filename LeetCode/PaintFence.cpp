class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;
        int x = k;
        int y = k * k;
        int z = (x + y) * (k - 1);
        for (int i = 3; i <= n; i++) {
            z = (x + y) * (k - 1);
            x = y;
            y = z;
        }
        return z;
    }
};