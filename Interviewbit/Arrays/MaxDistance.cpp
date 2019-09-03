int Solution::maximumGap(const vector<int> &arr){

    int n = arr.size();
    // not possible
    if(n == 1)
        return 0;
    // minimum [0:i] at index i
    vector<int> left(n);
    // maximum [i:n] at index i
    vector<int> right(n);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i = 1; i < n; i++)
        left[i] = min(left[i-1], arr[i]);
    for(int i = n - 2; i >= 0; i--)
        right[i] = max(right[i+1], arr[i]);
    int i = 0, j = 0, ans = -1;
    while(i < n && j < n){
        if(left[i] <= right[j]){
            ans = max(ans, j - i);
            j++;
        }
        else
            i++;
    }
    return ans;

}
