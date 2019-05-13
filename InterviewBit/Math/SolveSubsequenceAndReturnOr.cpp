int Solution::solve(vector<int> &A) {
    
    int ans = A[0];
    int size = A.size();
    for(int i = 1; i < size; i++)
        ans = __gcd(ans, A[i]);
    if(ans == 1)
        return 1;
    else
        return 0;

}