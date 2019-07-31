class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto ele : nums)
            mp[ele]++;
        priority_queue<pair<int, int>> pq;
        for(auto ele : mp)
            pq.push({ele.second, ele.first});
        vector<int> ans;
        while(k--){
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};