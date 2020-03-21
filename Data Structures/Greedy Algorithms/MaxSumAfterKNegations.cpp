#include<bits/stdc++.h>
using namespace std;

/**
 * Return maximum sum possible after K negations in the given array
 * Negation means replace an element in array by -1 * element
 * 
 * Idea : Use Greedy Approach, Do K negations on Minimum Element recursively.
 */
int solve(vector<int> &arr, int k){
    // using min heap for efficient insertion and deletions
    priority_queue<int, vector<int>, greater<int>> pq;
    // insert all elements into the heap
    for(auto ele : arr)
        pq.push(ele);
    // perform negations on minimum element k times
    while(k--){
        int temp = pq.top();
        pq.pop();
        pq.push((-1) * temp);
    }
    // find sum of elements of heap
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> arr = {-2, 0, 5, -1, 2};
    int k = 4;
    cout <<solve(arr, k) <<"\n";
    return 0;
}