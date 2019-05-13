int Solution::solve(vector<int> &arr, int k) {
    int n = arr.size();
    int count = 0; 
    for (int i = 0; i < n; ++i) 
        if (arr[i] <= k) 
            ++count;
    int bad = 0; 
    for (int i = 0; i < count; ++i) 
        if (arr[i] > k) 
            ++bad;
    int ans = bad; 
    for (int i = 0, j = count; j < n; ++i, ++j) {
        if (arr[i] > k) 
            --bad;
        if (arr[j] > k) 
            ++bad;
        ans = min(ans, bad); 
    } 
    return ans;
}
