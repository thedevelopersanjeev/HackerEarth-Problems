#include<bits/stdc++.h>

// Subarray with maximum number of 0s - maximum number of 1s
vector<int> Solution::flip(string str) {

    // length of the string
    int len = str.size();
    // number of zeros and ones
    int zeros = 0, ones = 0;
    // for marking starting variable of a subarray
    int start = 0;
    // for storing maximum number of 0s - maximum number of 1s
    int max = INT_MIN;
    // final answer for starting and ending index of subarray
    int s = 0, e = 0;
    for(int i = 0; i < len; i++){
        if(str[i] == '0')
            zeros++;
        else 
            ones++;
        if(zeros - ones < 0){
            // maximum reduced
            start = i + 1;
            zeros = 0;
            ones = 0;
        }
        if(max < (zeros - ones)){
            // new maximum found
            max = zeros - ones;
            s = start;
            e = i;
        }
    }
    vector<int> ans;
    if(max > 0){
        ans.push_back(s + 1);
        ans.push_back(e + 1);
    }
    return ans;

}
