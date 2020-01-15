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

#include <bits/stdc++.h>
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
    long long t, n, m;
    cin >>t;
    while(t--){
        cin >>n >>m;
        vector<vector<long long>> arr(n, vector<long long>(m));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++)
                cin >>arr[i][j];
        }
        long long ans = 0;
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < m; j++){
                long long right = j + 1;
                long long left = j - 1;
                long long top = i - 1;
                long long bottom = i + 1;
                long long x = 1;
                while(left >= 0 && right < m && arr[i][left] == arr[i][right] && top >= 0 && bottom < n && arr[top][j] == arr[bottom][j]){
                    x += 2;
                    left--;
                    right++;
                    top--;
                    bottom++;
                }
                ans += (x + 1) / 2;
            }
        }
        cout <<ans <<"\n";
    }
    return 0;
}
