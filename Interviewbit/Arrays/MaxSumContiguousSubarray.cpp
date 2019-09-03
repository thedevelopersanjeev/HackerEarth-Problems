#include<bits/stdc++.h>

// Kadane's Algorithm
// Return Maximum Subarray Sum
int Solution::maxSubArray(const vector<int> &arr) {
    // Base Cases
    // Empty Array
    if(arr.size() == 0)
        return 0;
    
    // Single Element Array
    if(arr.size() == 1)
        return arr[0];
    int n = arr.size();
    // Maximum Subarray Sum Encountered till index i
    int maxSoFar = arr[0];
    // Maximum Sum Ending till index i
    int maxEndingHere = arr[0];
    for(int i = 1; i < n; i++){
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }    
    return maxSoFar;

}
