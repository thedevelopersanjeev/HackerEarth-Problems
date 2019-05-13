int Solution::solve(int A) {
    int ans = 0;
    for(int i = 1; i <= A; i *= 10){
        int temp = i * 10;
        ans += ((A/temp) * i) + min(max(A%temp-i+1, 0), i);
    }
    return ans;
}
