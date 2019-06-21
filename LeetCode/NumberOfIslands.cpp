class Solution {
public:
    bool isSafe(vector<vector<char>> &arr, int i, int j, int m, int n, vector<vector<bool>> &visited){
        return (i >= 0 && j >= 0 && i < m && j < n && arr[i][j] == '1' && !visited[i][j]);
    }
    
    void dfs(vector<vector<char>> &arr, vector<vector<bool>> &visited, int i, int j, int m, int n){
        visited[i][j] = true;
        if(isSafe(arr, i+1, j, m, n, visited))
            dfs(arr, visited, i+1, j, m, n);
        if(isSafe(arr, i-1, j, m, n, visited))
            dfs(arr, visited, i-1, j, m, n);
        if(isSafe(arr, i, j+1, m, n, visited))
            dfs(arr, visited, i, j+1, m, n);
        if(isSafe(arr, i, j-1, m, n, visited))
            dfs(arr, visited, i, j-1, m, n);
        /**
        if(isSafe(arr, i+1, j+1, m, n, visited))
            dfs(arr, visited, i+1, j+1, m, n);
        if(isSafe(arr, i-1, j-1, m, n, visited))
            dfs(arr, visited, i-1, j-1, m, n);
        if(isSafe(arr, i-1, j+1, m, n, visited))
            dfs(arr, visited, i-1, j+1, m, n);
        if(isSafe(arr, i-1, j-1, m, n, visited))
            dfs(arr, visited, i+1, j-1, m, n);
        */
    }
    
    int numIslands(vector<vector<char>>& arr) {
        
        if(arr.empty())
            return 0;
        
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<bool>> visited;
        for(int i = 0; i < m; i++){
            vector<bool> temp;
            for(int j = 0; j < n; j++)
                // visited[i][j] = false;
                temp.push_back(false);
            visited.push_back(temp);
        }
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(arr, visited, i, j, m, n);
                }
            }
        }
        
        return ans;
        
    }
};