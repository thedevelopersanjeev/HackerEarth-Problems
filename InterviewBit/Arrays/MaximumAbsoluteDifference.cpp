int Solution::maxArr(vector<int> &A) {
    int ma = INT_MIN;
    int mi = INT_MAX;
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int n = A.size();
    for(int i = 0; i < n; i++){
        ma = max(ma, A[i]+i);
        mi = min(mi, A[i]+i);
        max1 = max(max1, A[i]-i);
        min1 = min(min1, A[i]-i);
    }
    return max(max1-min1, ma-mi);
}