#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007LL
#define PI 2 * acos(0)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool powerOfTwo(int n)
{
    if (n == 1)
        return true;
    while (n > 1)
    {
        if (n % 2 == 1)
        {
            return false;
        }
        n /= 2;
    }
    return 1;
}

void solve()
{
    string s;
    int m, li, ri, ki;
    cin >> s >> m;
    while (m--)
    {
        cin >> li >> ri >> ki;
        li--;
        ri--;
        ki %= (ri - li + 1);
        s = s.substr(0, li) + s.substr(ri - ki + 1, ki) + s.substr(li, ri - li + 1 - ki) + s.substr(ri + 1);
    }
    cout << s << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
