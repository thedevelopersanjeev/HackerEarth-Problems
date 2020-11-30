#include <bits/stdc++.h>
using namespace std;

// adjacency list of the graph
vector<vector<int>> adj;
int n;  // number of nodes
vector<bool> visited(n, false);
vector<int> intime(n, 0), outtime(n, 0);
int timer = 0;

void dfs(int u) {
    intime[u] = timer++;
    visited[u] = true;
    for (const auto &v : adj[u]) {
        if (visited[v] == false) {
            dfs(v);
        }
    }
    outtime[u] = timer++;
}