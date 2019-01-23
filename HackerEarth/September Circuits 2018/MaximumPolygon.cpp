#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef pair <ld, int> ldi;
 
const int Maxn = 122;
 
int n, m;
int X[Maxn], Y[Maxn];
ld len[Maxn][Maxn];
ll cr[Maxn][Maxn][Maxn];
int mn;
int hull[Maxn];
ld dp[Maxn][Maxn];
 
ll Cross(int a, int b, int c)
{
    int ax = X[b] - X[a], ay = Y[b] - Y[a];
    int bx = X[c] - X[a], by = Y[c] - Y[a];
    return ll(ax) * by - ll(ay) * bx;
}
 
ld Len(int ax, int ay) { return sqrt(ld(ax) * ax + ld(ay) * ay); }
 
bool Less(const ldi &a, const ldi &b)
{
    if (cr[mn][a.second][b.second] == 0)
        return len[mn][a.second] < len[mn][b.second];
    return a.first < b.first;
}
 
bool Check(ld x)
{
    for (int a = 0; a < n && n - a >= m; a++) {
        for (int j = a + 1; j < n; j++)
            dp[2][j] = -x * len[hull[a]][hull[j]];
        for (int i = 3; i <= m; i++)
            for (int j = a + i - 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j - 1] + ld(cr[hull[a]][hull[j - 1]][hull[j]]) / 2.0l 
                                            - x * len[hull[j - 1]][hull[j]];
                for (int k = j - 2; k >= a + i - 2; k--)
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + ld(cr[hull[a]][hull[k]][hull[j]]) / 2.0l
                                                          - x * len[hull[k]][hull[j]]);
            }
        for (int j = a + m - 1; j < n; j++)
            if (dp[m][j] - x * len[hull[a]][hull[j]] >= 0)
                return true;
    }
    return false;
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            len[i][j] = Len(X[i] - X[j], Y[i] - Y[j]);
            for (int k = 0; k < n; k++)
                cr[i][j][k] = Cross(i, j, k);
        }
    vector <ldi> seq;
    mn = 0;
    for (int i = 1; i < n; i++)
        if (X[i] < X[mn] || X[i] == X[mn] && Y[i] < Y[mn]) mn = i;
    for (int i = 0; i < n; i++) if (i != mn)
        seq.push_back(ldi(atan2(ld(Y[i] - Y[mn]), ld(X[i] - X[mn])), i));
    sort(seq.begin(), seq.end(), Less);
    int pnt = int(seq.size()) - 1;
    while (pnt >= 0 && cr[mn][seq.back().second][seq[pnt].second] == 0) pnt--;
    if (pnt < 0) { printf("0.0000\n"); return 0; }
    reverse(seq.begin() + pnt + 1, seq.end());
    hull[0] = mn;
    for (int i = 0; i < seq.size(); i++)
        hull[i + 1] = seq[i].second;
    ld lef = 0, rig = 4e18l;
    for (int t = 0; t < 90; t++) {
        ld mid = (lef + rig) / 2.0l;
        if (Check(mid)) lef = mid;
        else rig = mid;
    }
    cout << fixed << setprecision(4) << lef << endl;
    return 0;
}