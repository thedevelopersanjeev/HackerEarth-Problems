#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, ele, l, r;
    cin >>n >>q;
    vector<int> arr;
    for(int i=0; i<n; i++){
        cin >>ele;
        arr.push_back(ele);
    }
    while(q--){
        cin >>l >>r;
        l = l-1;
        r = r-1;
        int res = 0, cur = 0;
        for (int i = 0; i <= l-1; i++)
            res = max(res, cur = arr[i] + max(0, cur));
        for(int i=r; i>=l; i--)
            res = max(res, cur = arr[i] + max(0, cur));
        for(int i=r+1; i<arr.size(); i++)
            res = max(res, cur = arr[i] + max(0, cur));
        cout <<res <<endl;
    }
    return 0;
}