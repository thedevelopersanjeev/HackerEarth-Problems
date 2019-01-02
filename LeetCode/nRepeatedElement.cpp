class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> mp;
        for(auto x : A){
            mp[x]++;
        }
        for(auto x : mp){
            if(x.second == A.size()/2)
                return x.first;
        }
    }
};