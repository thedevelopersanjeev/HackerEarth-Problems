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

int ans = 0;
vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {-1, 0, 1, 0};

void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, vector<pair<int, int>> &components, int i, int j)
{
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        return;
    if (visited[i][j])
        return;
    if (board[i][j] == '*')
    {
        ans++;
        return;
    }
    visited[i][j] = true;
    components.push_back(make_pair(i, j));
    for (int k = 0; k < 4; k++)
        dfs(board, visited, components, i + dx[k], j + dy[k]);
}

void solve()
{
    int n, m, k, x, y;
    cin >> n >> m >> k;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '.' && visited[i][j] == false)
            {
                vector<pair<int, int>> components;
                ans = 0;
                dfs(board, visited, components, i, j);
                for (const auto &ele : components)
                {
                    dp[ele.first][ele.second] = ans;
                }
            }
        }
    }
    while (k--)
    {
        cin >> x >> y;
        x--;
        y--;
        cout << dp[x][y] << "\n";
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