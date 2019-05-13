vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int m = A.size();
    int n = A[0].size();
    // prefix sum rows
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++)
            A[i][j] += A[i][j-1];
    }
    // prefix sum columns
    for(int j = 0; j < n; j++){
        for(int i = 1; i < m; i++)
            A[i][j] += A[i-1][j];
    }
    vector<int> ans;
    int size = B.size();
    for(int i = 0; i < size; i++){
        int b = B[i];
        int c = C[i];
        int d = D[i];
        int e = E[i];
        int s1 = A[d-1][e-1];
        int s2 = 0;
        if(c-2 >= 0)
            s2 = A[d-1][c-2];
        int s3 = 0;
        if(b-2 >= 0)
            s3 = A[b-2][e-1];
        int s4 = 0;
        if(b-2 >= 0 && c-2 >= 0)
            s4 = A[b-2][c-2];
        ans.push_back(s1-s2-s3+s4);
    }
    return ans;
}
