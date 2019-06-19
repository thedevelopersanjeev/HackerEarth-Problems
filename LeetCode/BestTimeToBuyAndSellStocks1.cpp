class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min = INT_MAX;
        int ans = 0;
        
        for(auto ele : prices){
            
            if(ele < min)
                min = ele;
            else
                ans = max(ans, ele - min);
            
        }
        
        return ans;
    }
};