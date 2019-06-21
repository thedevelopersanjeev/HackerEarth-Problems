class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        
        // getting the dimensions of matrix
        int m = arr.size(), n = arr[0].size();
        queue<int> rotten;
        map<int, int> depth;
        // add all rotten oranges to queue
        // also, add their coordinate with depth in depth hashmap
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // check if current orange is rotten or not
                if(arr[i][j] == 2){
                    // insert all starting vertices for bfs in queue
                    rotten.push(i*n + j);
                    // for starting vertex, depth is 0
                    depth[i*n + j] = 0;
                }
            }
        }
        int ans = 0;
        // start BFS
        while(!rotten.empty()){
            int temp = rotten.front();
            rotten.pop();
            // as we added i*n + j into the queue
            // we can get them back using n only
            int currentI = temp / n;
            int currentJ = temp % n;
            // check for upper column
            int topI = currentI - 1;
            int topJ = currentJ;
            // check if upper column is safe and has a fresh orange
            if(0 <= topI && topI < m && topJ >= 0 && topJ < n && arr[topI][topJ] == 1){
                // it will be rotten now
                arr[topI][topJ] = 2;
                rotten.push(topI*n + topJ);
                depth[topI*n + topJ] = depth[temp] + 1;
                ans = depth[topI*n + topJ];
            }
            // check for lower column
            int lowI = currentI + 1;
            int lowJ = currentJ;
            // check if lower column is safe and has a fresh orange
            if(0 <= lowI && lowI < m && lowJ >= 0 && lowJ < n && arr[lowI][lowJ] == 1){
                // it will be rotten now
                arr[lowI][lowJ] = 2;
                rotten.push(lowI*n + lowJ);
                depth[lowI*n + lowJ] = depth[temp] + 1;
                ans = depth[lowI*n + lowJ];
            }
            // check for left column
            int leftI = currentI;
            int leftJ = currentJ - 1;
            // check if left column is safe and has a fresh orange
            if(0 <= leftI && leftI < m && leftJ >= 0 && leftJ < n && arr[leftI][leftJ] == 1){
                // it will be rotten now
                arr[leftI][leftJ] = 2;
                rotten.push(leftI*n + leftJ);
                depth[leftI*n + leftJ] = depth[temp] + 1;
                ans = depth[leftI*n + leftJ];
            }
            // check for right column
            int rightI = currentI;
            int rightJ = currentJ + 1;
            // check if right column is safe and has a fresh orange
            if(0 <= rightI && rightI < m && rightJ >= 0 && rightJ < n && arr[rightI][rightJ] == 1){
                // it will be rotten now
                arr[rightI][rightJ] = 2;
                rotten.push(rightI*n + rightJ);
                depth[rightI*n + rightJ] = depth[temp] + 1;
                ans = depth[rightI*n + rightJ];
            }
        }
        // check if any orange is left unrotten
        for(auto row : arr){
            for(auto ele : row){
                if(ele == 1)
                    return -1;
            }
        }
        // return the final answer
        return ans;
        
    }
};