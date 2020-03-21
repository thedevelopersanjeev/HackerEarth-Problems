// Given a graph, find the level of each node in the graph.
#include<bits/stdc++.h>
using namespace std;

// find and return level of each node in the graph
// start : start node (level 0 node)
// nodes : number of nodes in the graph
// adj   : adjacency list of the graph
vector<int> findLevels(int start, int nodes, vector<int> adj[]){
    vector<int> visited(nodes + 1, false);
    vector<int> levels(nodes + 1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        // for all neighbours of current node
        // process each node one by one
        for(auto ele : adj[current]){
            // if not visited, then only process current node
            if(!visited[ele]){
                // mark level of this node
                levels[ele] = levels[current] + 1;
                // add this node to queue
                q.push(ele);
                // mark this node as visited
                visited[ele] = true;
            }
        }
    }
    return levels;
}

int main(){
    int nodes;
    cout <<"Enter number of nodes : ";
    cin >>nodes;
    vector<int> adj[nodes+1];
    int edges;
    cout <<"Enter number of edges : ";
    cin >>edges;
    while(edges--){
        cout <<"Enter edges : ";
        int x, y;
        cin >>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> levels = findLevels(1, nodes, adj);
    cout <<"Node : Level\n";
    for(int i = 1; i <= levels.size(); i++)
        cout <<i <<" : " <<levels[i] <<"\n";
    return 0;
}