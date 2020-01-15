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
    string s;
    cin >>t;
    while(t--){
        cin >>n >>s;
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < n; i++)
            mp[s[i]].push_back(i);
        int tx = -1, ty = -1;
        int fmn = INT_MAX;
        for(auto ele : mp){
            vector<int> curr = ele.second;
            if(curr.size() > 1){
                int mn = INT_MAX;
                int x = -1, y = -1;
                for(int i = 1; i < curr.size(); i++){
                    if(curr[i] - curr[i-1] < mn){
                        mn = curr[i] - curr[i-1];
                        x = curr[i-1];
                        y = curr[i];
                    }
                }
                if(mn < fmn){
                    fmn = mn;
                    tx = x;
                    ty = y;
                }
            }
        }
        if(tx == -1 || ty == -1)
            cout <<0 <<"\n";
        else 
            cout <<tx + n - ty <<"\n";
        
    }
    return 0;
}
