void Solution::rotate(vector<vector<int> > &arr) {
    int n = arr.size();
    // find the transpose of matrix
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++)
            swap(arr[i][j], arr[j][i]);
    }
    // reverse each row
    for(int i = 0; i < n; i++)
        reverse(arr[i].begin(), arr[i].end());
}
