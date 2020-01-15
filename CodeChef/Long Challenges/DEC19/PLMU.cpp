/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >>arr[i];
        int cnt = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 2)
                cnt++;
            else if(arr[i] == 0)
                cnt2++;
        }
        cout <<((cnt * (cnt - 1)) / 2) + ((cnt2 * (cnt2 - 1)) / 2) <<"\n";
    }
    return 0;
}
