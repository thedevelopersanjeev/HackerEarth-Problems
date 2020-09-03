/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";
#define int long long
#define mod 1000000007

const double PI = 2 * acos(0.0);
const long long INF = 1e18L + 5;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 1;
vector<int> adj[N];
vector<int> deg(N);
vector<bool> visited(N, false);
vector<int> component;
int n, m, u, v;

void dfs(int s) {
	visited[s] = true;
	component.push_back(s);
	for (auto edge : adj[s]) {
		if (!visited[edge]) {
			dfs(edge);
		}
	}
}

void solve() {
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			component.clear();
			dfs(i);
			bool ok = true;
			for (auto ele : component) {
				ok &= (deg[ele] == 2);
			}
			if (ok)
				ans++;
		}
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
