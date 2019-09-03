#include<bits/stdc++.h>

int Solution::maxArr(vector<int> &arr) {
    
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        max1 = max(max1, arr[i] + i + 1);
        min1 = min(min1, arr[i] + i + 1);
        max2 = max(max2, arr[i] - i - 1);
        min2 = min(min2, arr[i] - i - 1);
        ans = max(ans, max(max1 - min1, max2 - min2));
    }
    return ans;

}