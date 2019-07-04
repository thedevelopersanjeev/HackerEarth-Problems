public class Solution {
    
    int n, m, ans;
    int xx[] = new int[]{1, 0, 0, -1};
    int yy[] = new int[]{0, 1, -1, 0};

    boolean isV(int u, int v, int a[][]) {
        return 0 <= u && u < n && 0 <= v && v < m && a[u][v] != -1;
    }

    void recur(int x, int y, int cnt, int a[][]) {
        if(a[x][y] == 2) {
            if(cnt == 0)    ans++;
            return;
        }
        a[x][y] = -1;
        for(int i = 0; i < 4; i++) {
            int u = x + xx[i];
            int v = y + yy[i];
            if(isV(u, v, a)) {
                recur(u, v, cnt - 1, a);
            }
        }
        a[x][y] = 0;
    }
    public int solve(int[][] a) {
        n = a.length;   m = a[0].length;
        ans = 0;
        int u = -1, v = -1, cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1) {
                    u = i;    v = j;
                } else if(a[i][j] == 0)    cnt++;
            }
        }
        assert(u != -1);
        recur(u, v, cnt + 1, a);
        return ans;
    }
    
}
