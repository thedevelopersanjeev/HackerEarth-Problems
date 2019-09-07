#include<bits/stdc++.h>

int Solution::sqrt(int num){

    if(num == 0 || num == 1)
        return num;

    int low = 1, high = num, ans;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid <= num / mid){
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;

}
