// Given two arrays A and B, find N Pairs (Ai, Bj) having maximum sum.
// A = {1, 2}
// B = {3, 4}
// C = {6, 5} <-- Answer (2 + 4) and (2 + 3)
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> A, vector<int> B){
    // max heap to store the max sum and corresponding indexes i and j
    priority_queue<pair<int, pair<int, int>>> pq;
    // sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    // size of input arrays
    int n = A.size();
    // map to check if a pair has been inserted into the heap or not
    map<pair<int, int>, int> mp;
    pq.push({A[n-1] + B[n-1], {n-1, n-1}});
    mp[{n-1, n-1}] = 1;
    int start = 1;
    vector<int> ans;
    while(start <= n){
        // get current max from top of heap
        auto curr = pq.top();
        // remove it
        pq.pop();
        // add it to answer array
        ans.push_back(curr.first);
        // considering pair (i-1, j)
        pair<int, int> p1 = {curr.second.first - 1, curr.second.second};
        // check if this pair has not been inserted into the heap
        // we can check this using the map mp
        if(mp[p1] == 0){
            // add this element to heap
            pq.push({A[p1.first] + B[p1.second], p1});
            mp[p1] = 1;
        }
        // considering pair (i, j-1)
        pair<int, int> p2 = {curr.second.first, curr.second.second - 1};
        if(mp[p2] == 0){
            // add this element to heap
            pq.push({A[p2.first] + B[p2.second], p2});
            mp[p2] = 1;
        }
        start++;
    }
    return ans;
}

int main(){
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    auto ans = solve(A, B);
    for(auto ele : ans)
        cout <<ele <<"\n";
    return 0;
}