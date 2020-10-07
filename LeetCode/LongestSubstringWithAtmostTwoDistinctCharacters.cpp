class Solution {
public:
    
    int getMin(unordered_map<char, int> &mp) {
        int ans = INT_MAX;
        
        for (const auto &ele : mp) {
            ans = min(ans, ele.second);
        }
        
        return ans;
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size(), ans = 2, i = 0, j = 0;
        unordered_map<char, int> mp;
        
        if (n < 3) {
            return n;
        }
        
        while (j < n) {
            if(mp.size() < 3) {
                mp[s[j]] = j;
                j++;
            }
            if(mp.size() == 3) {
                int idx = getMin(mp);
                mp.erase(s[idx]);
                i = idx + 1;
            }
            ans = max(ans, j - i);
        }
        
        return ans;
    }
};