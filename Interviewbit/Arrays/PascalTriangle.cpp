vector<vector<int>> Solution::solve(int n){

    vector<vector<int>> ans;
    if(n == 0)
        return ans;
    ans.resize(n);
    ans[0].push_back(1);
    for(int i = 1; i < n; i++){
        ans[i].push_back(1);
        for(int j = 1; j < i; j++)
            ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
        ans[i].push_back(1);
    }
    return ans;

}
