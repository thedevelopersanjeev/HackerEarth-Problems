vector<int> Solution::getRow(int n){

    vector<int> ans(n + 1, 1);
    for(int i = 0; i <= n; i++){
        vector<int> temp = ans;
        for(int j = 1; j < i; j++)
            ans[j] = temp[j-1] + temp[j];
    }
    return ans;

}
