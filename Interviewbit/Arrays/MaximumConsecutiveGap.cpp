int Solution::maximumGap(const vector<int> &arr){
    
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    int ans = INT_MIN;
    int n = arr.size();
    if(n < 2)
        return 0;
    for(int i = 1; i < n; i++)
        ans = max(ans, temp[i] - temp[i-1]);
    return ans;

}
