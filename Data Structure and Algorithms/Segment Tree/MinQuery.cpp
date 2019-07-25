#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout <<#x <<" " <<x <<endl;

vector<int> tree;
vector<int> arr;

void build(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2*node], tree[2*node + 1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
    }
    else{
        int mid = start + (end - start) / 2;
        if(idx >= start && idx <= mid){
            update(2*node, start, mid, idx, val);
        }
        else{
            update(2*node + 1, mid + 1, end, idx, val);
        }
        tree[node] = min(tree[2*node], tree[2*node + 1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l > end or r < start)
        return 100005;
    if(l <= start && r >= end)
        return tree[node];
    int mid = start + (end - start) / 2;
    return min(query(2*node, start, mid, l, r), query(2*node + 1, mid + 1, end, l, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >>n >>q;
    arr.resize(n+1);
    tree.resize(2*n);
    for(int i = 1; i <= n; i++)
        cin >>arr[i];
    build(1, 1, n);
    char ch;
    while(q--){
        cin >>ch;
        if(ch == 'q'){
            int l, r;
            cin >>l >>r;
            cout <<query(1, 1, n, l, r) <<"\n";
        }
        else{
            int x, y;
            cin >>x >>y;
            update(1, 1, n, x, y);
        }
    }
    return 0;
}
