#include<bits/stdc++.h>
using namespace std;


void update(int arr[], int size, int id, int val){
    if(val == 0)
        return;
    arr[id-1] = arr[id-1] + val;
    if(id == size){
        update(arr, size, 1, val-1);
    }
    else{
        update(arr, size, id+1, val-1);
    }
}

int query(int arr[], int size, int l, int r){
    if(l == r)
        return arr[l-1];
    if(l == size)
        return arr[l-1] + query(arr, size, 1, r);
    else
        return arr[l-1] + query(arr, size, l+1, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, ele;
    int type, a, b;
    cin >>n >>q;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >>arr[i];
    while(q--){
        cin >>type;
        if(type == 1){
            cin >>a >>b;
            update(arr, n, a, b);
        }
        else{
            cin >>a >>b;
            cout <<query(arr, n, a, b) <<endl;
        }
    }
    return 0; 
}