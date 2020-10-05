class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        for(int i = 1; i <= sqrt(area); i++) {
            if(area % i == 0) {
                ans[0] = area / i;
                ans[1] = i;
            }
        }
        return ans;
    }
};