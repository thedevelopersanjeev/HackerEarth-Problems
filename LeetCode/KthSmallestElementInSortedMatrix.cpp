class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto row : matrix){
            for(auto ele : row)
                pq.push(ele);
        }
        for(int i = 1; i < k; i++)
            pq.pop();
        return pq.top();
    }
};