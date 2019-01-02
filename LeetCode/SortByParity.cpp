class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;
        for(auto x : A){
            if(x%2 == 0){
                ans.push_back(x);
            }
        }
        for(auto x : A){
            if(x%2 != 0){
                ans.push_back(x);
            }
        }
        return ans;
    }
};