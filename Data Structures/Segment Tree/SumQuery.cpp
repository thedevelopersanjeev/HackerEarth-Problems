// given an array of size n
// and q queries of type [l, r], return sum in range [l, r]
// and update query of type i val, update value at index i to val
// Naive Algorithm Approach takes Linear Time.
// using Segment Tree we can reduce it to Logarithmic Time.

#include<bits/stdc++.h>
using namespace std;

vector<int> tree;
vector<int> arr;

// recursive method to build the segment tree using bottom up approach
// fill value at index node in tree considering the array elements from
// index start to end both inclusive.
// index i has its children at index 2 * i and 2 * i + 1
// fill value at 2 * i and 2 * i + 1 first
// then at their parent using them.
// node is the index in tree
// start and end is the range in the array
// Time Complexity : O(n)
void build(int node, int start, int end){
    if(start == end){
        // leaf node in the segment tree
        // base case
        tree[node] = arr[start];
    }
    else{
        // find middle element index
        int mid = start + (end - start) / 2;
        // recursive call on left child
        build(2 * node, start, mid);
        // recursive call on right child
        build(2 * node + 1, mid + 1, end);
        // current node will have sum of both its children
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

// update an value at index idx to val in the array
// this update will cause some value in the nodes of tree to be changed
// to update the tree elements, check where the idx lies in [start, end] range
// node is the index in tree
// idx is the index in array
// start and end in the range in the array
// Time Complexity : O(log(n))
void update(int node, int start, int end, int idx, int val){
    if(start == end){
        // base case
        // leaf node
        // update value
        arr[idx] += val;
        tree[node] += val;
    }
    else{
        // find mid element index
        int mid = start + (end - start) / 2;
        if(idx >= start && idx <= mid){
            // idx lies in left subtree
            // recursive call on left subtree
            update(2*node, start, mid, idx, val);
        }
        else{
            // idx lies in right subtree
            // recursive call on right subtree
            update(2*node + 1, mid + 1, end, idx, val);
        }
        // update current node's value
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

int query(int node, int start, int end, int l, int r){
    if(l > end or r < start)
        // invalid range
        return 0;
    if(l <= start && r >= end)
        // given range is completely inside [start, end]
        // answer is present in current node
        return tree[node];
    // given range is partially inside and partially outside
    // find mid point
    int mid = start + (end - start) / 2;
    // return final answer from both sides
    return query(2*node, start, mid, l, r) + query(2*node + 1, mid + 1, end, l, r);
}

int main(){
    int n, q, l, r, idx, val, type;
    cout <<"Enter the number of elements in array: ";
    cin >>n;
    // array of elements
    arr.resize(n+1);
    // segment tree size will be 2 * n - 1 as there are 2 * n - 1 nodes
    // keep the size of tree as 2 * n to access the elements using 1 based indexing
    tree.resize(2*n);
    cout <<"Enter the elements in array: ";
    for(int i = 1; i <= n; i++)
        cin >>arr[i];
    build(1, 1, n);
    cout <<"Enter the number of queries: ";
    cin >>q;

    cout <<"Tree Elements : \n";
    for(auto ele : tree)
        cout <<ele <<" ";
    cout <<"\n\n";

    while(q--){
        cin >>type;
        if(type == 1){
            // Query
            cin >>l >>r;
            cout <<query(1, 1, n, l, r) <<"\n";
        }
        else if(type == 2){
            // Update
            cin >>idx >>val;
            update(1, 1, n, idx, val);
        }
        else{
            cout <<"Invalid Query Type\n";
        }
    }
    return 0;
}