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
    int n, a, b, c, ans = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        if (arr[1] == 1 && arr[2] == 1)
            ans++;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
