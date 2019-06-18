int Solution::solve(int A) {

    int pow = 1, ans = 0;

    while(A){
        
        pow *= 5;
        
        if(A & 1)
            ans += pow;
        
        A >>= 1;
    }
    
    
    return ans;
}