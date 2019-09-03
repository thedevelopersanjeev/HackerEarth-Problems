#include<bits/stdc++.h>

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {

    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int n = arrive.size();
    for(int i = 0; i < n; i++){
        if((i + k) < n && arrive[i+k] < depart[i])
            return false;
    }
    return true;

}
