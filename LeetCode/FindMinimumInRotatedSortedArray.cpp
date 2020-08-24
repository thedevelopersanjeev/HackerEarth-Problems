class Solution {
public:
    int findMin(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))
            return min(nums[0], nums.back());
        int lo = 0, hi = nums.size() - 1;
        while(hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] >= nums[lo])
                lo = mid;
            else
                hi = mid;
        }
        return nums[hi];
    }
};