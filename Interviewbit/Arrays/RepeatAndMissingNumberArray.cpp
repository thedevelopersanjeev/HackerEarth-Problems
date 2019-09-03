#include<bits/stdc++.h>

vector<int> Solution::repeatedNumber(const vector<int> &arr) {
    
    long long diff1 = 0, diff2 = 0;
    long long n = arr.size();
    for(long long i = 0; i < n; i++){
        diff1 += ((long long)arr[i] - (i + 1));
        diff2 += ((long long)arr[i] * (long long)arr[i] - (i + 1) * (i + 1));
    }
    long long sum1 = diff2 / diff1;
    int repeated = (sum1 - diff1) / 2;
    int missing = (sum1 + diff1) / 2;
    vector<int> ans = {missing, repeated};
    return ans;
    
}