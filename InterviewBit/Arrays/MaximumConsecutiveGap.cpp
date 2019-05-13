int Solution::maximumGap(const vector<int> &A) {
    vector<int> arr = A;
    int n = arr.size();
    if(n < 2)
        return 0;
    sort(arr.begin(), arr.end());
    int ans = INT_MIN;
    for(int i = 1; i < n; i++)
        ans = max(ans, (arr[i] - arr[i-1]));
    return ans;
}
