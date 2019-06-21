int Solution::solve(vector<int> &A, int B) {

    sort(A.begin(), A.end());
    
    int n = A.size();
    
    int ans = INT_MAX;
    
    int i = 0, j = B - 1;
    while(j < n){
        ans = min(ans, A[j] - A[i]);
        i++;
        j++;
    }
    
    if(ans == 2147483647 || ans < 0)
        return 0;
    
    return ans;
    
}