class Solution {
  public:
	int minimumEffortPath(vector<vector<int>> &heights) {
		int n = heights.size(), m = heights[0].size();
		vector<pair<int, int>> delta = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
		priority_queue<Node> pq;
		vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
		Node currentNode = {0, 0, 0};
		pq.push(currentNode);
		while (!pq.empty()) {
			currentNode = pq.top();
			pq.pop();
			int x = currentNode.x, y = currentNode.y, d = currentNode.dist;
			if (x == n - 1 && y == m - 1) {
				return d;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + delta[k].first;
				int ny = y + delta[k].second;
				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					int nd = max(d, abs(heights[nx][ny] - heights[x][y]));
					if (ans[nx][ny] > nd) {
						ans[nx][ny] = nd;
						currentNode.x = nx;
						currentNode.y = ny;
						currentNode.dist = nd;
						pq.push(currentNode);
					}
				}
			}
		}
		return 0;
	}
  private:
	struct Node {
		int x;
		int y;
		int dist;

		bool operator<(const Node &rhs) const {
			return dist > rhs.dist;
		}
	};
};