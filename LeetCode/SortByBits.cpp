class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> temp;
        for(const auto &ele : arr) {
            temp.push_back({__builtin_popcount(ele), ele});
        }
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(const auto &ele : temp)
            ans.push_back(ele.second);
        return ans;
    }
};