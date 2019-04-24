class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int start = i + 1;
            int end = size - 1;
            while(start < end){
                int current = nums[i] + nums[start] + nums[end];
                if(current == target)
                    return target;
                else if(current < target)
                    start++;
                else
                    end--;
                int d1 = abs(current - target);
                int d2 = abs(ans - target);
                if(d1 < d2)
                    ans = current;
            }
        }
        return ans;
    }
};