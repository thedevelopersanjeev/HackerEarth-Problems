class Solution {
   public:
    bool isBipartite(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && dfs(adj, color, 1, i) == false) {
                return false;
            }
        }
        return true;
    }

   private:
    bool dfs(const vector<vector<int>> &adj, vector<int> &color, int c, int u) {
        if (color[u] != 0) {
            return color[u] == c;
        }
        color[u] = c;
        for (const auto &v : adj[u]) {
            if (dfs(adj, color, c * -1, v) == false) {
                return false;
            }
        }
        return true;
    }
};