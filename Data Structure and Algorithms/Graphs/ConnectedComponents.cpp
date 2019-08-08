#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> adj[]){
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]])
            dfs(adj[node][i], visited, adj);
    }
}

int main(){
    int n;
    cout <<"Enter the number of nodes : ";
    cin >>n;
    vector<int> adj[n+1];
    cout <<"Enter the number of edges : ";
    int e;
    cin >>e;
    while(e--){
        cout <<"Enter Edge : ";
        int x, y;
        cin >>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // boolean array to mark nodes as visited/unvisited
    vector<bool> visited(n+1, false);
    int connectedComponents = 0;
    for(int i = 1; i <= n; i++){
        // if ith node is not visited, start dfs from that node
        if(!visited[i]){
            dfs(i, visited, adj);
            connectedComponents++;
        }
    }
    cout <<"Number of connected components are : " <<connectedComponents <<"\n";
    return 0;
}