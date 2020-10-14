class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        int count=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            total+=nums[i];
            if(total==target){
                count++;
                total=0;
                m.erase(m.begin(), m.end());
            }
            else if(m.count(total-target)){
                count++;
                total=0;
                m.erase(m.begin(), m.end());
            }
            else m[total]++;
        }
        return count;
        
    }
};