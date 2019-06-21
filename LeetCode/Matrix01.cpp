class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        
        // get dimensions of matrix
        int m = arr.size();
        int n = arr[0].size();
        
        // initialise distance matrix with initial size INT_MAX
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        
        // queue for BFS
        queue<pair<int, int>> q;
        
        // add all 0s to queue
        // and mark their distance as 0
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 0){
                    distance[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
    
        // start BFS
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            // get current cell index
            int currentI = current.first;
            int currentJ = current.second;
            // upper cell
            int topI = currentI - 1;
            int topJ = currentJ;
            if(topI >= 0 && topJ >= 0 && topI < m && topJ < n){
                if(distance[topI][topJ] > distance[currentI][currentJ] + 1){
                    distance[topI][topJ] = distance[currentI][currentJ] + 1;
                    q.push(make_pair(topI, topJ));    
                }
            }
            // lower cell
            int lowI = currentI + 1;
            int lowJ = currentJ;
            if(lowI >= 0 && lowJ >= 0 && lowI < m && lowJ < n){
                if(distance[lowI][lowJ] > distance[currentI][currentJ] + 1){
                    distance[lowI][lowJ] = distance[currentI][currentJ] + 1;
                    q.push(make_pair(lowI, lowJ));    
                }
            }
            // left cell
            int leftI = currentI;
            int leftJ = currentJ - 1;
            if(leftI >= 0 && leftJ >= 0 && leftI < m && leftJ < n){
                if(distance[leftI][leftJ] > distance[currentI][currentJ] + 1){
                    distance[leftI][leftJ] = distance[currentI][currentJ] + 1;
                    q.push(make_pair(leftI, leftJ));    
                }
            }
            // right cell
            int rightI = currentI;
            int rightJ = currentJ + 1;
            if(rightI >= 0 && rightJ >= 0 && rightI < m && rightJ < n){
                if(distance[rightI][rightJ] > distance[currentI][currentJ] + 1){
                    distance[rightI][rightJ] = distance[currentI][currentJ] + 1;
                    q.push(make_pair(rightI, rightJ));    
                }
            }
        }
        // return distance matrix
        return distance;
    }
};