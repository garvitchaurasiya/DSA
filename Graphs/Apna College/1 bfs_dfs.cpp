#include "bits/stdc++.h"
using namespace std;

// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3
// 1

vector<vector<int>> adj(1e6);

void bfs(int source){
    
    vector<bool> vis(1e6, false);
    
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while(!q.empty()){
        int frontElement = q.front();
        cout<<frontElement<<' ';
        q.pop();

        for (auto it: adj[frontElement]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }

}

void dfs(int source){
    vector<bool> vis(1e6, false);
    
    cout<<source<<' ';
    vis[source] = true;

    for (auto it : adj[source]) {
        if(!vis[it])
            dfs(it);
    }
}

int main(){

    int nodes, edges; cin>>nodes>>edges;

    for (int i=0; i<edges; i++){
        int v1, v2; cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    int source; cin>>source;
    bfs(source);
    cout<<'\n';
    dfs(source);

    return 0;
}