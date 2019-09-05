#include<bits/stdc++.h>

// flag == true --> First Occurrence of Element in arr
// flag == false --> Last Occurence of Element in arr
int binarySearchUtil(vector<int> arr, int low, int high, int ele, bool flag){

    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == ele){
            ans = mid;
            // check if we are counting left elements
            // or right elements
            if(flag){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(arr[mid] > ele){
            // search on left
            high = mid - 1;
        }
        else{
            // search on right
            low = mid + 1;
        }
    }
    return ans;

}

int Solution::findCount(const vector<int> &arr, int ele){

    int high = arr.size() - 1;
    int low = 0;
    if(binarySearchUtil(arr, low, high, ele, true) == -1)
        return 0;
    return 1 + binarySearchUtil(arr, low, high, ele, false) - binarySearchUtil(arr, low, high, ele, true);

}
