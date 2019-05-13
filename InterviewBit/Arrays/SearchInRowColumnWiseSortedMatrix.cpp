int Solution::solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(binary_search(A[i].begin(), A[i].end(), B)){
            int j = find(A[i].begin(), A[i].end(), B) - A[i].begin();
            return (((i+1) * 1009) + (j + 1));
        }
    }
    return -1;
}