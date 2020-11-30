#include <bits/stdc++.h>
using namespace std;

// adjacency list of the graph
vector<vector<int>> adj;
// number of nodes in the graph
int n;

void bfs(int source) {
    queue<int> q;
    vector<bool> visited(n, false);
    // distance of each node from the source node
    vector<int> dis(n, 0);
    // for restoring the path
    vector<int> par(n, -1);
    // restoring path from to source node
    vector<int> path;
    int from;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto &v : adj[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);
                // going to v in next layer from u in current layer
                dis[v] = dis[u] + 1;
                par[v] = u;
            }
        }
    }

    if (visited[from] == false) {
        // no path from source to from node
    } else {
        for (int u = from; u != -1; u = par[u]) {
            path.push_back(u);
        }
        reverse(path.begin(), path.end());
    }
}