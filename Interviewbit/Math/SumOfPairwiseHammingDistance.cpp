#include<bits/stdc++.h>

int Solution::hammingDistance(const vector<int> &arr){

    const long long mod = 1000000007;
    long long n = arr.size();
    long long ans = 0;
    for(long long bit = 0; bit < 31; bit++){
        long long ones = 0, zeros = 0;
        for(long long i = 0; i < n; i++){
            if(arr[i] & (1 << bit))
                ones++;
            else 
                zeros++;
        }
        ans = (ans + (2 * zeros * ones) % mod) % mod;
    }
    return (int)(ans % mod);

}
