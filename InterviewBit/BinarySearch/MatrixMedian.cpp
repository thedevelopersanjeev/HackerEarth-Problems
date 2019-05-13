int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    int mi = INT_MAX, ma = INT_MIN;
    for(int i = 0; i < n; i++){
        mi = min(mi, A[i][0]);
        ma = max(ma, A[i][m-1]);
    }
    int x = (m*n + 1) / 2;
    while(mi < ma){
        int mid = (ma + mi) / 2;
        int y = 0;
        for(int i = 0; i < n; i++)
            y += (upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin());
        if(y < x)
            mi = mid + 1;
        else
            ma = mid;
    }
    return mi;
}