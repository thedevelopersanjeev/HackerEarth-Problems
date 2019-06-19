int Solution::solve(vector<int> &A, int B) {
    int ans = 0, i = 0, j = A.size() - 1;
    
    while(i < j){
        
        if(A[i] == B - A[j]){
            ans++;
            i++;
            j--;
        }
        else if(A[i] < B - A[j])
            i++;
        else
            j--;
        
    }
    
    return ans;
}
