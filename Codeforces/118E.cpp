#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

// C(n, r) = n! / (r! * (n - r)!)
// C(n, r) = C(n, n - r)
// C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
int nCr(int n, int r) {
    long double res = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return (int) (res + 0.01);
}

// (x ^ y) % mod
int modpow(int x, int y, int m) {
    x %= m;
    int res = 1LL;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int timer;
bool flag;
vector<pair<int, int>> ans;

void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &in, vector<int> &lo, int u, int par) {
    visited[u] = true;
    in[u] = lo[u] = timer++;
    for(const auto &v : adj[u]) {
        if(v == par) {
            continue;
        }
        if(visited[v] == true) {
            // u --> v is a back edge
            lo[u] = min(lo[u], lo[v]);
            if(in[u] > in[v]) {
                ans.push_back({u + 1, v + 1});
            }
        } else {
            dfs(adj, visited, in, lo, v, u);
            // u --> v is a bridge
            if(lo[v] > in[u]) {
                flag = true;
                return;
            }
            // u --> v is a forward edge
            ans.push_back({u + 1, v + 1});
            lo[u] = min(lo[u], lo[v]);
        }
    }
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n];
    while(m--) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> in(n, 0);
    vector<int> lo(n, 0);
    vector<bool> visited(n, false);
    flag = false;
    ans.clear();
    timer = 0;
    dfs(adj, visited, in, lo, 0, -1);
    if(flag == true) {
        cout << 0;
    } else {
        for(const auto &ele : ans) {
            cout << ele.first << " " << ele.second << "\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
