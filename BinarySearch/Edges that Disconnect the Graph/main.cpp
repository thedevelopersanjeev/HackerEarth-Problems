int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin, low;
int timer, ans;

void dfs(int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : adj[v]) {
		if (to == p) {
			continue;
		}
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v]) {
				ans++;
			}
		}
	}
}

int solve(vector<vector<int>> &graph) {
	n = graph.size();
	adj = graph;
	timer = 0;
	ans = 0;
	visited.resize(n, false);
	tin.resize(n, -1);
	low.resize(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	return ans;
}