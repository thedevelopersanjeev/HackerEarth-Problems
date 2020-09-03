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

template<class... Args>
auto create(size_t n, Args&&... args) {
	if constexpr(sizeof...(args) == 1)
		return vector(n, args...);
	else
		return vector(n, create(args...));
}

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args), ...);
}


const int N = 2e3 + 1;
vector<vector<int>> dp(N, vector<int>(N, -1));

void solve() {
	int n, h, l, r;
	read(n, h, l, r);
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		read(arr[i]);
	dp[0][0] = 0;
	for (int i = 1; i < h; i++)
		dp[0][i] = -1;
	for (int i = 0; i < n; i++) {
		for (int hr = 0; hr < h; hr++) {
			dp[i + 1][hr] = -1;
		}
		for (int hr = 0; hr < h; hr++) {
			if (dp[i][hr] == -1) {
				continue;
			}
			int h1 = (hr + arr[i] - 1 + h) % h;
			int h2 = (hr + arr[i]) % h;
			dp[i + 1][h1] = max(dp[i + 1][h1], dp[i][hr] + (l <= h1 && h1 <= r));
			dp[i + 1][h2] = max(dp[i + 1][h2], dp[i][hr] + (l <= h2 && h2 <= r));
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		if (dp[n][i] != -1) {
			ans = max(ans, dp[n][i]);
		}
	}
	write(ans);
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
