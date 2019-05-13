int Solution::solve(vector<vector<int> > &arr) {
    int m = arr.size();
    int n = arr[0].size();
    // prefix sum rows
    for(int i = m-2; i >= 0; i--){
        for(int j = 0; j < n; j++)
            arr[i][j] += arr[i+1][j];
    }
    // prefix sum columns
    for(int i = 0; i < m; i++){
        for(int j = n-2; j >= 0; j--)
            arr[i][j] += arr[i][j+1];
    }
    int ans = INT_MIN;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            ans = max(ans, arr[i][j]);
    }
    return ans;
}
