#include<bits/stdc++.h>

int split(vector<long> &presum, long target){
    int cnt = 0;
    auto it = presum.begin() + 1;
    while(it != presum.end()){
        it--;
        it = upper_bound(presum.begin(), presum.end(), *it + target);
        cnt++;
    }
    return cnt;
}

int Solution::paint(int painters, int time, vector<int> &boards){

    const int mod = 10000003;
    int n = boards.size();
    vector<long> presum(n + 1, 0);
    long low = INT_MIN, high;
    for(int i = 0; i < n; i++){
        low = max(low, (long)boards[i]);
        presum[i+1] = boards[i] + presum[i];
    }
    high = presum.back();
    while(low < high){
        long mid = low + (high - low) / 2;
        if(split(presum, mid) > painters){
            // more number of painters are required than available painters
            // hence, answer lies in right region
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return (low * time) % mod;

}
