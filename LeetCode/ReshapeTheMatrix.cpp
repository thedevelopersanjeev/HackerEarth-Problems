class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        if((n * m) != (r * c)) {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        vector<int> temp;
        for(const auto &row : nums) {
            for(const auto &ele : row) {
                temp.push_back(ele);
            }
        }
        int x = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans[i][j] = temp[x];
                x++;
            }
        }
        return ans;
    }
};