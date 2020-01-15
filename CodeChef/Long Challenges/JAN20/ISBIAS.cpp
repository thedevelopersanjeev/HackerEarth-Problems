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
#include <boost/functional/hash.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int n, q, l, r;
    cin >>n >>q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >>arr[i];
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[i-1])
            dp[i] = 1;
    while(q--){
        cin >>l >>r;
        int x = dp[r-1] - dp[l];
        if(l > 0){
            if(arr[l] > arr[l-1])
                x++;
            else 
                x--;
        }
        cout <<(x == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}