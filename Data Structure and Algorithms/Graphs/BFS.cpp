#include<bits/stdc++.h>
using namespace std;

/**
 * Prints BFS Traversal of given graph from start node
 * graph : Input Graph
 * nodes : Total Number of Nodes
 * start  : Start Node
 **/
void printBFS(vector<int> graph[], int nodes, int start){
    vector<int> q;
    q.push_back(start);
    vector<bool> visited(nodes + 1, false);
    visited[start] = true;
    cout <<start <<" ";
    while(!q.empty()){
        int curr = q.back();
        q.pop_back();
        for(auto ele : graph[curr]){
            if(!visited[ele]){
                visited[ele] = true;
                cout <<ele <<" ";
                q.push_back(ele);
            }
        }
    }
    cout <<"\n";
}

int main(){
    cout <<"Enter the number of nodes : ";
    int n;
    cin >>n;
    vector<int> adj[n+1];
    int x;
    cout <<"Enter the number of edges : ";
    cin >>x;
    int a, b;
    while(x--){
        cout <<"Enter Edge : ";
        cin >>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printBFS(adj, n, 1);
    return 0;
}