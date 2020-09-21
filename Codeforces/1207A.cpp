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
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    int ans = 0;
    if (h > c) {
        while (b >= 2 && p > 0) {
            b -= 2;
            p--;
            ans += h;
        }
        while (b >= 2 && f > 0) {
            b -= 2;
            f--;
            ans += c;
        }
    } else {
        while (b >= 2 && f > 0) {
            b -= 2;
            f--;
            ans += c;
        }
        while (b >= 2 && p > 0) {
            b -= 2;
            p--;
            ans += h;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}