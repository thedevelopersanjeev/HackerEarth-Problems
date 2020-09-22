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
    int a = 1, b = n, mx = n - 1;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int x = i;
            int y = n / i;
            if ((y - x) < mx) {
                mx = y - x;
                a = x;
                b = y;
            }
        }
    }
    cout << a << " " << b;
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