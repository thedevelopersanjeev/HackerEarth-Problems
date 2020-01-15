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
    int t, n, pi, si;
    cin >>t;
    while(t--){
    	cin >>n;
    	unordered_map<int, int> mp;
    	for(int i = 0; i < n; i++){
    		cin >>pi >>si;
    		if(pi < 9){
    			mp[pi] = max(mp[pi], si);
    		}
    	}
    	int ans = 0;
    	for(auto ele : mp){
    		ans += ele.second;
    	}
    	cout <<ans <<"\n";
    }
    return 0;
}