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
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int twofivesix = min({k2, k5, k6});
    k2 -= twofivesix;
    if(k2 <= 0) {
        cout << twofivesix * 256;
    } else {
        cout << (twofivesix * 256) + (min(k2, k3) * 32);
    }
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