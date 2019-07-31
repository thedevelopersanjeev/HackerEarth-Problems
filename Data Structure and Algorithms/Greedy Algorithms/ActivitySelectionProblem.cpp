// You are given n activities with their start and finish times. 
// Select the maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time.
// example : start = [10, 12, 20]
// end = [20, 25, 30]
// Answer : 2 [{10, 20}, {20, 30}]
#include<bits/stdc++.h>
using namespace std;

// comparator to sort activities based on ending time
bool comp(const pair<int, int> &A, const pair<int, int> &B){
    return A.second < B.second;
}

int main(){
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(5, 9));
    arr.push_back(make_pair(1, 2));
    arr.push_back(make_pair(3, 4));
    arr.push_back(make_pair(0, 6));
    arr.push_back(make_pair(5, 7));
    arr.push_back(make_pair(8, 9));
    sort(arr.begin(), arr.end(), comp);
    int i = 0, n = arr.size();
    cout <<arr[0].first <<" " <<arr[0].second <<"\n";
    for(int j = 1; j < n; j++){
        if(arr[j].first >= arr[i].second){
            cout <<arr[j].first <<" " <<arr[j].second <<"\n";
            i = j;
        }
    }
    return 0;
}