class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<char> jewels;
        for(int i = 0; i < J.size(); i++){
            jewels.push_back(J[i]);
        }
        int ans = 0;
        sort(jewels.begin(), jewels.end());
        for(int i = 0; i < S.size(); i++){
            if(binary_search(jewels.begin(), jewels.end(), S[i]))
                ans++;
        }
        return ans;
    }
};