int Solution::solve(vector<vector<int> > &arr) {
    int m = arr.size();
    int n = arr[0].size();
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            ans += (((i+1)*(j+1))*(m-i)*(n-j)*arr[i][j]);
    }
    return ans;
}