vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    vector<vector<int>> ans;
    for(auto ele : B){
        vector<int> temp(A.size());
        ele %= A.size();
        rotate_copy(A.begin(), A.begin() + ele, A.end(), temp.begin());
        ans.push_back(temp);
    }
    return ans;
}
