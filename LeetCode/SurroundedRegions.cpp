class Solution {
public:
    void solve(vector<vector<char>>& arr) {
        
        // base case
        if(arr.empty())
            return;
        
        // get the dimensions of board
        int m = arr.size();
        int n = arr[0].size();
        
        // bool visited[m][n];
        vector<vector<bool>> visited;
        
        // mark all as unvisited first
        for(int i = 0; i < m; i++){
            vector<bool> temp;
            for(int j = 0; j < n; j++)
                temp.push_back(false);
            visited.push_back(temp);
        }
            
        // top row and bottom row
        for(int j = 0; j < n; j++){
            if(arr[0][j] == 'O' && !visited[0][j])
                dfs(arr, visited, 0, j, m, n);
            
            if(arr[m-1][j] == 'O' && !visited[m-1][j])
                dfs(arr, visited, m-1, j, m, n);
        }
        
        // left column and right column
        for(int i = 0; i < m; i++){
            if(arr[i][0] == 'O' && !visited[i][0])
                dfs(arr, visited, i, 0, m, n);
            
            if(arr[i][n-1] == 'O' && !visited[i][n-1])
                dfs(arr, visited, i, n-1, m, n);
        }
        
        // flip all zeros
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 'Y')
                    arr[i][j] = 'O';
                else if(arr[i][j] == 'O')
                    arr[i][j] = 'X';
            }
        }
        
    }
    
    void dfs(vector<vector<char>> &arr, vector<vector<bool>> &visited, int i, int j, int m, int n){
        visited[i][j] = true;
        arr[i][j] = 'Y';
        // upper cell
        if(i-1 >= 0 && i-1 < m && j >= 0 && j < n && !visited[i-1][j] && arr[i-1][j] == 'O')
            dfs(arr, visited, i-1, j, m, n);
        // lower cell
        if(i+1 >= 0 && i+1 < m && j >= 0 && j < n && !visited[i+1][j] && arr[i+1][j] == 'O')
            dfs(arr, visited, i+1, j, m, n);
        // left cell
        if(i >= 0 && i < m && j-1 >= 0 && j-1 < n && !visited[i][j-1] && arr[i][j-1] == 'O')
            dfs(arr, visited, i, j-1, m, n);
        // right cell
        if(i >= 0 && i < m && j+1 >= 0 && j+1 < n && !visited[i][j+1] && arr[i][j+1] == 'O')
            dfs(arr, visited, i, j+1, m, n);
    }
};