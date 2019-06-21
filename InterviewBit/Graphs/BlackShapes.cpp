void dfs(vector<string> &arr, int i, int j){
    
    int m = arr.size();
    int n = arr[0].size();
    
    if(i < 0 || j < 0 || i >= m || j >= n)
        return;
    
    if(arr[i][j] != 'X')
        return;
        
    arr[i][j] = 'O';
    
    dfs(arr, i+1, j);
    dfs(arr, i-1, j);
    dfs(arr, i, j+1);
    dfs(arr, i, j-1);
}

int Solution::black(vector<string> &A) {

    int m = A.size();
    int n = A[0].size();
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 'X'){
                dfs(A, i, j);
                ans++;
            }
        }
    }
    return ans;
    
}