public class Solution {

    boolean can(int m, int a[], int c) {
        int j = 0, n = a.length, d = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] - a[j] >= m) {
                j = i;
                d++;
            }
        }
        return d >= c;
    }

    public int solve(int[] a, int c) {
        
        Arrays.sort(a);
    int l = 0, r = (int)(2e9);
    for(int i = 0; i < 100; i++) {
        int m = l + (r - l) / 2;
        if(can(m, a, c))  l = m;
        else    r = m;
    }
    return l;
        
    }
}
