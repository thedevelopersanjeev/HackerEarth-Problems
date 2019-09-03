#include<bits/stdc++.h>

int Solution::maxSpecialProduct(vector<int> &arr){

    long long n = arr.size();
    const long long mod = 1000000007;
    // stores next greater element index on right
    vector<long long> right(n, -1);
    // stores next greater element index on left
    vector<long long> left(n, -1);
    // stack stores {ele, index}
    stack<pair<long long, long long>> st;
    // for next greater element on right
    // iterate the array from right to left
    // when we are at a particular index, we already know that
    // next greater element is present in the stack
    for(long long i = n - 1; i >= 0; i--){
        // pop elements from stack while stack is not empty and 
        // stack top is less than current element
        while(!st.empty() && st.top().first <= arr[i])
            st.pop();
        // if stack becomes empty, there is no next greater element on right
        if(st.empty())
            right[i] = 0;
        else 
            right[i] = st.top().second;
        // push next element into stack
        st.push(make_pair(arr[i], i));
    }
    // clear the stack
    while(!st.empty())
        st.pop();
    // for next greater element on left
    // iterate the array from left to right
    // when we are at a particular index, we already know that
    // next greater element on left is present in the stack
    for(long long i = 0; i < n; i++){
        // pop elements from the stack while the stack is not empty and
        // stack top is less than current element 
        while(!st.empty() && st.top().first <= arr[i])
            st.pop();
        // if stack becomes empty, there is no next greater element on left
        if(st.empty())
            left[i] = 0;
        else    
            left[i] = st.top().second;
        // push next element into stack
        st.push(make_pair(arr[i], i));
    }
    long long ans = INT_MIN;
    for(long long i = 0; i < n; i++)
        ans = max(ans, (left[i] * right[i]));
    return (int)(ans % mod);
}