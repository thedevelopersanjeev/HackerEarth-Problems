#include<bits/stdc++.h>

vector<int> Solution::plusOne(vector<int> &num) {
    
    int n = num.size();
    vector<int> result;    
    reverse(num.begin(), num.end());
    int carry = 1;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int curr = num[i] + carry;
        if(curr >= 10){
            ans.push_back(curr % 10);
            carry = curr / 10;
        }
        else{
            ans.push_back(curr);
            carry = 0;
        }
    }
    if(carry > 0)
        ans.push_back(carry);
    while(ans[ans.size()-1] == 0)
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;

}