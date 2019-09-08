#include<bits/stdc++.h>

int Solution::findMedian(vector<vector<int>> &matrix){

    // matrix dimensions
    int n = matrix.size();
    int m = matrix[0].size();
    // minimum and maximum element
    int mn = matrix[0][0];
    int mx = mn;
    for(int i = 0; i < n; i++){
        mn = min(mn, matrix[i][0]);
        mx = max(mx, matrix[i][m-1]);
    }
    // number of elements <= desire
    // then, that element is median
    int desire = (1 + (m * n)) / 2;
    while(mn < mx){
        // middle element of matrix, expected to be median
        int mid = (mn + mx) / 2;
        // number of elements <= mid
        int cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        if(cnt < desire)
            // median lies in right half
            mn = mid + 1;
        else
            // median lies in left half
            mx = mid;

    }
    return mn;

}
