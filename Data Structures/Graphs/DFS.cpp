// Depth First Search on a Graph...
#include<bits/stdc++.h>
using namespace std;

int main(){
    cout <<"Enter the number of nodes in the graph : ";
    int n;
    cin >>n;
    cout <<"Enter the number of edges in the graph : ";
    int e;
    cin >>e;
    int u, v;
    // adjacency list of graph
    vector<int> adj[n+1];
    while(e--){
        cout <<"Enter Edge : ";
        cin >>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout <<"Starting Depth First Search..." <<"\n";
    int s;
    cout <<"Enter starting node : ";
    cin >>s;
    // boolean array to keep track of visited nodes
    // bool visited[n+1, false];
    vector<bool> visited(n+1, false);
    visited[s] = true;
    stack<int> sta;
    sta.push(s);
    while(!sta.empty()){
        int v = sta.top();
        sta.pop();
        cout <<v <<"->";
        for(auto ele : adj[v]){
            if(!visited[ele]){
                sta.push(ele);
                visited[ele] = true;
            }
        }
    }
    return 0;
}