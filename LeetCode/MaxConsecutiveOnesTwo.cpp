class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, ans = 0, cnt = 0;
        for (const auto &ele : nums) {
            cnt++;
            if (ele == 0) {
                curr = cnt;
                cnt = 0;
            }
            ans = max(ans, cnt + curr);
        }
        return ans;
    }
};