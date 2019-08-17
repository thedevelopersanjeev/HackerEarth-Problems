class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pairs) {
        vector<int> adj[n];
        for(auto edge : pairs)
            adj[edge[1]].push_back(edge[0]);
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++){
            for(auto ele : adj[i])
                indegree[ele]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto ele : adj[curr])
                if(--indegree[ele] == 0)
                    q.push(ele);
        }
        return (ans.size() == n);
    }
};