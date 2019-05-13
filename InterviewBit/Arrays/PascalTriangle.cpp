vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ans;
    for(int i = 1; i <= A; i++){
        int c = 1;
        vector<int> temp;
        for(int j = 1; j <= i; j++){
            temp.push_back(c);
            c = c * (i - j) / j;
        }
        ans.push_back(temp);
    }
    return ans;
}
