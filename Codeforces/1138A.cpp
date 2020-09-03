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

void solve() {
	int n;
	cin >> n;
	int prev = 0, ans = 0, cnt = 0, gcnt = 0, curr;
	for(int i = 0; i < n; i++) {
		cin >> curr;
		if(curr == prev) {
			cnt++;
		} else {
			gcnt = cnt;
			cnt = 1;
		}
		prev = curr;
		ans = max(ans, 2 * min(cnt, gcnt));
	}
	cout << ans;
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
    while(tc--) {
        solve();
    }
    return 0;
}
