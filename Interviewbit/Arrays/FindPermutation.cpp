#include<bits/stdc++.h>

vector<int> Solution::findPerm(const string s, int n){

    vector<int> arr;
    for(int i = 1; i <= n; i++)
        arr.push_back(i);
    vector<int> ans;
    int first = 0, last = n - 1;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'D'){
            // decreasing, pick max element
            ans.push_back(arr[last]);
            last--;
        }
        else{
            // increasing, pick min element
            ans.push_back(arr[first]);
            first++;
        }
    }
    ans.push_back(arr[last]);
    return ans;

}
