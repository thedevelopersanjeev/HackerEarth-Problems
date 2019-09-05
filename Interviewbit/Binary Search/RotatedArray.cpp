#include<bits/stdc++.h>

int binarySearchUtil(vector<int> arr, int low, int high){

    int n = arr.size();
    while(low <= high){
        int mid = (low + high) / 2;
        // array already sorted
        if(arr[low] < arr[high])
            return low;
        // current mid element as pivot
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if(arr[mid] < arr[next] && arr[mid] < arr[prev])
            return mid;
        // pivot is present in left subarray
        if(arr[mid] < arr[high])
            high = mid - 1;
        else   
            // pivot is present in right subarray
            low = mid + 1;
    }

}

int Solution::findMin(const vector<int> &arr){
    
    int low = 0;
    int high = arr.size() - 1;
    if(arr.size() == 1)
        return arr[0];
    return arr[binarySearchUtil(arr, low, high)];

}
