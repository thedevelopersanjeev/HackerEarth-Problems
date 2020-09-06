class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y){
            string xy = to_string(x) + to_string(y);
            string yx = to_string(y) + to_string(x);
            return xy > yx;
        });
        string ans = "";
        for(const auto &ele : nums)
            ans += to_string(ele);
        return (ans[0] == '0' ? "0" : ans);
    }
};