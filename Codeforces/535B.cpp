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

void f(vector<int> &arr, int curr) {
	if(curr >= 1e9) {
		return;
	}
	arr.push_back(curr);
	f(arr, (curr * 10) + 4);
	f(arr, (curr * 10) + 7);
	return;
}

void solve() {
	int n;
	cin >> n;
	vector<int> cache;
	f(cache, 4);
	f(cache, 7);
	sort(cache.begin(), cache.end());
	cout << upper_bound(cache.begin(), cache.end(), n) - cache.begin();
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
