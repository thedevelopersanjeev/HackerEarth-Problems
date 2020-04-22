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

vector<int> Solution::solve(int n, vector<vector<int>> &queries) {

	vector<int> arr(n, 0);
	vector<int> ans;
	for (auto query : queries) {
		if (query[0] == 1) {
			int i = query[1];
			i--;
			arr[i] = (2 * arr[i]) + 1;
		}
		else if (query[0] == 2) {
			int i = query[1];
			i--;
			arr[i] = arr[i] / 2;
		}
		else {
			int curr = 0;
			for (int i = query[1]; i < query[2]; i++)
				curr += __builtin_popcount(arr[i]);
			ans.push_back(curr);
		}
	}
	return ans;

}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	return 0;
}
