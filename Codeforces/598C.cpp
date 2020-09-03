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
#define PI acosl(-1)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int n;
    long double x, y;
    cin >> n;
    vector<pair<long double, int>> arr;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        long double theta = atan2l(y, x) * (180 / PI);
        arr.push_back({theta, i});
    }
    sort(arr.begin(), arr.end());
    pair<int, int> ans = {-1, -1};
    long double mn = LDBL_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        long double curr = abs(arr[i].first - arr[(i + 1) % arr.size()].first);
        curr = min(curr, 360 - curr);
        if (curr <= mn)
        {
            mn = curr;
            ans.first = arr[i].second;
            ans.second = arr[(i + 1) % arr.size()].second;
        }
    }
    cout << ans.first << " " << ans.second << "\n";
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