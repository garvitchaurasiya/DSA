#include "bits/stdc++.h"
using namespace std;

bool checkCycle(int src, vector<vector<int>> &adj, vector<bool> vis, int parent){
    vis[src] = true;
    for (auto i: adj[src]){
        if(i!=parent){
            if(vis[i]){
                return true;
            }
            if(!vis[i] && checkCycle(i, adj, vis, src) ){
                return true;
            }
        }
    }
    return false;
}

int main(){

    int vertices, edges; cin>>vertices>>edges;

    vector<vector<int>> adj(vertices);

    for (int i=0; i<edges; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool isCycle = false;
    vector<bool> vis(vertices, false);
    for (int i=0; i<vertices; i++){
        if(!vis[i] && checkCycle(i, adj, vis, -1)){
            isCycle = true;
        }
    }

    if(isCycle)
        cout<<"Cycle is present";
    else{
        cout<<"Cycle is not present";
    }

    return 0;
}