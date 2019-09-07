#include<bits/stdc++.h>

int Solution::firstMissingPositive(vector<int> &arr){

    int n = arr.size();
    for(int i = 0; i < n; i++){
        // if current element is in range [1:N]
        // it is of our use...
        if(arr[i] > 0 && arr[i] <= n){
            // find the position where it should be in sorted array
            int pos = arr[i] - 1;
            if(arr[pos] != arr[i]){
                swap(arr[pos], arr[i]);
                i--;
            }
        }
    }
    // if i + 1 is not there on any index, thats the first missing +ve integer...
    for(int i = 0; i < n; i++){
        if(arr[i] != i + 1)
            return i + 1;
    }
    // if all integers are there [1:N] then, 
    // first missing +ve integer is N + 1.
    return n + 1;

}
