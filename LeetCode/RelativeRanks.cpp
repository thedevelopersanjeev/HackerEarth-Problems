class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> arr = nums;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<string> ans;
        for(const auto &ele : arr) {
            if(ele == nums[0]) {
                ans.push_back("Gold Medal");
            } else if (ele == nums[1]) {
                ans.push_back("Silver Medal");
            } else if (ele == nums[2]) {
                ans.push_back("Bronze Medal");
            } else {
                ans.push_back(to_string(distance(nums.begin(), find(nums.begin(), nums.end(), ele)) + 1));
            }
        }
        return ans;
    }
};