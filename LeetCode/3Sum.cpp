class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int sz = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int j = (sz - 1) / 2;

        for (int i = 0; i < sz - 2; i++) {
            if (i > 0 && nums[i - 1] >= 0) //{0,0,0,0}
                break;
            while (i > 0 && nums[i] == nums[i - 1])
                i++;
            for (int k = sz - 1; k > i + 1; k--) {
                while (k > i + 2 && nums[k] == nums[k - 2]) {
                    k--;
                }
                if (nums[i] + 2 * nums[k] < 0)   //{-5,*,2}
                    break;
                if (nums[i] * 2 + nums[k] > 0)	//{-2,*,5}
                    continue;

                if (j <= i)   //make sure j is between i and k
                    j = i + 1;
                else if (j >= k)
                    j = k - 1;


                int tmp = nums[i] + nums[k];

                if (tmp + nums[j] == 0) {
                    res.push_back({ nums[i] , nums[j] , nums[k] });                   
                }
                else if (tmp + nums[j] > 0) {
                    while (nums[j - 1] > -tmp)
                        j--;
                    if (nums[j - 1] == -tmp && j - 1 > i) {
                        res.push_back({ nums[i] , nums[j - 1] , nums[k] });
                    }
                }
                else {
                    while (nums[j + 1] < -tmp)
                        j++;
                    if (nums[j + 1] == -tmp && j + 1 < k) {
                        res.push_back({ nums[i] , nums[j + 1] , nums[k] });
                    }
                }
                if (nums[k] == nums[k - 1])
                    k--;
            }
        }
        return res;
        
    }
};