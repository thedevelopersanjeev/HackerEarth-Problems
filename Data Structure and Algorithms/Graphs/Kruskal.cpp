#include<bits/stdc++.h>
using namespace std;

// returns the root of given node
int root(int node, vector<int> &id){
    // for parent 
    // id[x] = x
    // so, keep moving up till we reach to parent
    while(id[node] != node){
        id[node] = id[id[node]];
        node = id[node];
    }
    // return the parent node
    return node;
}

// performs union of node x and node y
void union1(int x, int y, vector<int> &id){
    // find root of x
    int a = root(x, id);
    // find root of y
    int b = root(y, id);
    // attach root of both nodes
    id[a] = id[b];
}

// Return Minimum Spanning Tree using Kruskal Algorithm
// nodes : Number of nodes in the Graph
// adj   : Edges of the graph represented as {w, {x, y}}
// where there is an edge between x and y having weight w.
// edges are already sorted according to their weights
int kruskal(int nodes, vector<pair<int, pair<int, int>>> adj){
    // iterate over the edges of graph
    int ans = 0;
    // id array used for disjoint set
    vector<int> id(nodes + 1);
    // assign id to each node
    for(int i = 0; i <= nodes; i++)
        id[i] = i;
    for(auto edge : adj){
        // extract current edge's information
        int x = edge.second.first;
        int y = edge.second.second;
        int w = edge.first;
        // check if x and y don't form a cycle
        // using disjoint set
        if(root(x, id) != root(y, id)){
            ans += w;
            // add x and y into same set
            union1(x, y, id);
        }
    }
    return ans;
}

int main(){
    int nodes, edges;
    cout <<"Enter number of nodes : ";
    cin >>nodes;
    cout <<"Enter number of edges : ";
    cin >>edges;
    // {w, {x, y}}
    // edge between x and y having weight w
    vector<pair<int, pair<int, int>>> adj(edges);
    for(int i = 0; i < edges; i++){
        int w, x, y;
        cout <<"Enter edge weight : ";
        cin >>w;
        cout <<"Enter the edge : ";
        cin >>x >>y;
        adj[i] = {w, {x, y}};
    }
    // sort the edges according to edge weights
    sort(adj.begin(), adj.end());
    cout <<"Minimum Cost Spanning Tree : " <<kruskal(nodes, adj) <<"\n";
    return 0;
}