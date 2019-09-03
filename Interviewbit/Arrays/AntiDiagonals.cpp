vector<vector<int>> Solution::diagonal(vector<vector<int>> &matrix){

    int n = matrix.size();
    vector<vector<int>> ans;
    for(int row = 0; row < n; row++){
        vector<int> temp;
        int i = 0, j = row;
        while(j >= 0){
            temp.push_back(matrix[i][j]);
            i++;
            j--;
        }
        ans.push_back(temp);
    }
    for(int row = 1; row < n; row++){
        int i = row, j = n - 1;
        vector<int> temp;
        while(i < n){
            temp.push_back(matrix[i][j]);
            i++;
            j--;
        }
        ans.push_back(temp);
    }
    return ans;

}
