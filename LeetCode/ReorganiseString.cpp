class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                if(freq[i] > (n + 1) / 2)
                    return "";
                pq.push({freq[i], (char)('a' + i)});
            }
        }
        string ans = "";
        while(pq.size() >= 2){
            auto curr1 = pq.top();
            pq.pop();
            auto curr2 = pq.top();
            pq.pop();
            ans += curr1.second;
            ans += curr2.second;
            if(--curr1.first > 0)
                pq.push(curr1);
            if(--curr2.first > 0)
                pq.push(curr2);
        }
        if(pq.size() > 0)   
            ans += pq.top().second;
        return ans;
        
    }
};