#include<bits/stdc++.h>
using namespace std;

int prim(int nodes, int start, vector<pair<int, int>> adj[]){
    // create min heap of edges to select next promising edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // boolean array to mark nodes as visited
    vector<bool> marked(nodes + 1, false);
    // push starting node into queue
    q.push({0, start});
    // current cost
    int ans = 0;
    while(!q.empty()){
        // get next node having minimum cost
        auto curr = q.top();
        // remove from queue
        q.pop();
        // get the node which this edge connects
        int x = curr.second;
        // if that node has already been visited, it will form a cycle
        // so prevent that
        if(marked[x])
            continue;
        // add its cost to final answer
        ans += curr.first;
        // mark next node as visited
        marked[x] = true;
        // add all neighbours of next node into queue if not visited
        for(auto ele : adj[x]){
            int y = ele.second;
            if(!marked[y])
                q.push(ele);
        }
    }
    // return final answer
    return ans;
}

int main(){
    int nodes, edges;
    cout <<"Enter the number of nodes : ";
    cin >>nodes;
    cout <<"Enter the number of edges : ";
    cin >>edges;
    // adjacency list of edges
    // {weight, edge}
    vector<pair<int, int>> adj[nodes + 1];
    while(edges--){
        int x, y, w;
        cout <<"Enter weight : ";
        cin >>w;
        cout <<"Enter edge : ";
        cin >>x >>y;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
    // run Prim's algorithm by selecting 1 as starting node
    cout <<"Minimum Cost Spanning Tree : " <<prim(nodes, 1, adj) <<"\n";
    return 0;
}