class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int n, int m, int xo, int yo) {
        vector<pair<int, pair<int, int>>> temp;
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                int d = abs(x - xo) + abs(y - yo);
                temp.push_back({d, {x, y}});
            }
        }
        sort(temp.begin(), temp.end());
        vector<vector<int>> ans;
        for(const auto &ele : temp) {
            vector<int> curr = {ele.second.first, ele.second.second};
            ans.push_back(curr);
        }
        return ans;
    }
};