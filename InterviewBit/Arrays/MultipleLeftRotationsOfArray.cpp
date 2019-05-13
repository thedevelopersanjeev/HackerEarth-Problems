vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    vector<vector<int> > ans;
    for(auto ele : B){
        vector<int> temp = A;
        ele %= A.size();
        rotate(temp.begin(), temp.begin() + ele, temp.end());
        ans.push_back(temp);
    }
    return ans;
}
