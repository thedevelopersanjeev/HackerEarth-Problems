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

int N = 1e2 + 5;
int n;
vector<int> arr(N);

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.begin() + n);
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (binary_search(arr.begin(), arr.begin() + n, arr[i] * 2))
			continue;
		if (arr[i] % 3 == 0 && binary_search(arr.begin(), arr.begin() + n, arr[i] / 3))
			continue;
		last = arr[i];
		break;
	}
	vector<int> ans;
	ans.push_back(last);
	while (ans.size() != n) {
		if (last % 2 == 0 && binary_search(arr.begin(), arr.begin() + n, last / 2)) {
			ans.push_back(last / 2);
			last /= 2;
		}
		else {
			ans.push_back(last * 3);
			last *= 3;
		}
	}
	for (int i = n - 1; i >= 0; i--)
		cout << ans[i] << " ";
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
