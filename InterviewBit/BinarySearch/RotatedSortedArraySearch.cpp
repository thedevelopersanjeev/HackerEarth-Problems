int Solution::search(const vector<int> &nums, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(nums.empty()) return -1;
        int left = 0,right=nums.size()-1,mid;
        int numsBegin=nums[0];
        bool keyLeft=(target>=nums[0]);
        while(left<=right){
            mid=(left+right)/2;
        
            int tmp=nums[mid];
            if(tmp==target) return mid;
            bool numLeft=(tmp>=numsBegin);
            bool isGreater = (tmp>target);
            if((keyLeft && (!numLeft || isGreater)) 
               ||(!keyLeft && !numLeft && isGreater)){
                right = mid-1;
            }
            else left = mid+1;
        }
        return -1;
}
