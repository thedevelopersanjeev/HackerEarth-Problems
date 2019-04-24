class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for(auto ele : A)
            ans.push_back(ele*ele);
        sort(ans.begin(), ans.end());
        return ans;
    }
};