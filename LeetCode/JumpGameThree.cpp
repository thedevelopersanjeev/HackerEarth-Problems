class Solution {
   public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<int> visited(arr.size(), false);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            visited[curr] = true;
            if (arr[curr] == 0) {
                return true;
            }
            int left = curr - arr[curr];
            int right = curr + arr[curr];
            if (left >= 0 && left < arr.size() && visited[left] == false) {
                q.push(left);
            }
            if (right >= 0 && right < arr.size() && visited[right] == false) {
                q.push(right);
            }
        }
        return false;
    }
};