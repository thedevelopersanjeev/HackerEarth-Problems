#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007LL
#define PI acosl(-1)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dp[51][51][51];

int f(int n, int m, int k)
{
    if (dp[n][m][k] || (n * m) == k || k == 0)
    {
        return dp[n][m][k];
    }
    int ans = 1e9;
    for (int i = 1; i <= n - i; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ans = min(ans, (m * m) + f(i, m, k - j) + f(n - i, m, j));
        }
    }
    for (int i = 1; i <= m - i; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ans = min(ans, (n * n) + f(n, m - i, k - j) + f(n, i, j));
        }
    }
    return dp[n][m][k] = ans;
}

void solve()
{
    int t, n, m, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cout << f(n, m, k) << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}