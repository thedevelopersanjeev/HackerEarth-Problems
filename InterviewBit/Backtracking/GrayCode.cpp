vector<int> Solution::grayCode(int A) {

    if(A <= 0)
        return vector<int>{};
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    for(int i = 2; i < (1<<A); i = i<<1){
        for(int j = i-1; j >= 0; j--)
            ans.push_back(ans[j]);
        for(int j = 0; j < i; j++)
            ans[j] = "0" + ans[j];
        for(int j = i; j < 2*i; j++)
            ans[j] = "1" + ans[j];
    }
    vector<int> finalAns;
    for(auto ele : ans)
        finalAns.push_back(stoi(ele, nullptr, 2));
    return finalAns;

}