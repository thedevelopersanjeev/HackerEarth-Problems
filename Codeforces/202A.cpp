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

int findCount(string s, char ch) {
	int cnt = 0;
	for(auto &x : s) {
		if(ch == x)
			cnt++;
	}
	return cnt;
}

void solve() {
	string s;
	cin >> s;
	for(char ch = 'z'; ch >= 'a'; ch--) {
		int cnt = findCount(s, ch);
		if(cnt > 0) {
			while(cnt--)
				cout << ch;
			break;
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
    while(tc--) {
        solve();
    }
    return 0;
}
