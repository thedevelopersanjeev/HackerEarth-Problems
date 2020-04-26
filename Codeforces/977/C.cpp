/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
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

const int N = 2e5 + 5;
vector<int> arr(N);
int n, k;

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.begin() + n);
	int ans;
	if (k == 0)
		ans = arr[0] - 1;
	else
		ans = arr[k - 1];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] <= ans)
			++cnt;
	if (cnt != k || !(ans >= 1 && ans <= 1e9))
		ans = -1;
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