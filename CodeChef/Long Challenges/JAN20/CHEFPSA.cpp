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

const int mod = 1e9 + 7;
const int MAX = 1e5 + 1;

vector<int> fac(MAX, 1);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int t, n;
    cin >>t;
    for(int i = 2; i < MAX; i++)
        fac[i] = (fac[i-1] * i) % mod;
    while(t--){
        cin >>n;
        vector<int> arr(2*n);
        for(int i = 0; i < 2*n; i++)
            cin >>arr[i];
        int s = accumulate(arr.begin(), arr.end(), 0);
        if(s % (n + 1) != 0){
            cout <<"0\n";
            continue;
        }
        int x = s / (n + 1);
        sort(arr.begin(), arr.end());
        auto it = find(arr.begin(), arr.end(), x);
        if(it == arr.end()){
            cout <<"0\n";
            continue;
        }
        arr.erase(it);
        it = find(arr.begin(), arr.end(), x);
        if(it == arr.end()){
            cout <<"0\n";
            continue;
        }
        arr.erase(it);
        flag = false;
        int i = 0, j = 2 * n - 3;
        while(i < j){
            if(arr[i] + arr[j] != x){
                flag = true;
                break;
            }
            i++;
            j--;
        }
        if(flag){
            cout <<"0\n";
            continue;
        }
        int ans = 1;
        i = 0, j = 2 * n - 3;
        while(i < j){
            if(arr[i] != arr[j])
                ans = (ans * 2) % mod;
            i++;
            j--;
        }
        ans = (ans * fac[n-1]) % mod;
        
    }
    return 0;
}