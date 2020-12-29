class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += findCost(points[i], points[i + 1]);
        }
        return ans;
    }
    
private:
    int findCost(const vector<int> &a, const vector<int> &b) {
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]));
    }
};