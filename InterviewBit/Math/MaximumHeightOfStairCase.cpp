int Solution::solve(int A) {
    int temp = 1, ans = 0;
    while(temp <= A){
        A -= temp;
        temp++;
        ans++;
    }
    return ans;
}
