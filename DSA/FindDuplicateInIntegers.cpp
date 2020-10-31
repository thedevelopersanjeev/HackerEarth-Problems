class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int x = nums[0], y = nums[0];
        do {
            x = nums[x];
            y = nums[nums[y]];
        } while (x != y);
        x = nums[0];
        while (x != y) {
            x = nums[x];
            y = nums[y];
        }
        return x;
    }
};