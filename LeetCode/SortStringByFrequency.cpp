class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
                mp[s[i]]++;
        priority_queue<pair<int, char>> pq;
        for(auto ele : mp)
            pq.push({ele.second, ele.first});
        string ans = "";
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int count = curr.first;
            while(count--)
                ans += curr.second;
        }
        return ans;
        
    }
};