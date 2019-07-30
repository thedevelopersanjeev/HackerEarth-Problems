class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        // max heap 
        // stores the points as {distance, {x, y}}
        priority_queue<pair<double, pair<int, int>>> pq;
        // iterate over the points
        for(auto ele : arr){
            int x = ele[0];
            int y = ele[1];
            // calculate distance from origin
            double dist = sqrt((x*x) + (y*y));
            // if number of points in heap is less than required
            // number, insert it directly
            if(pq.size() < k)
                pq.push({dist, {x, y}});
            else{
                // need to check if new point is near to origin
                // when compared with the farthest point from origin
                // among current k points.
                auto curr = pq.top();
                if(curr.first > dist){
                    pq.pop();
                    pq.push({dist, {x, y}});
                }
            }
            
        }
        // max heap has k points which are nearest to origin
        vector<vector<int>> ans;
        // extract points from priority queue and store them in final answer
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int x = ele.second.first;
            int y = ele.second.second;
            ans.push_back(vector<int> {x, y});
        }
        return ans;
    }
};