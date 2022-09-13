#include "bits/stdc++.h"
using namespace std;

// A Topological Ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering.
// Topological ordering are NOT unique.
// Only Directed Acyclic Graph have a valid Topological Sort.

// 4 3
// 0 1
// 1 2
// 2 3

int main(){

    int vertices, edges; cin>>vertices>>edges;
    int count=0;

    vector<vector<int>> adj(vertices);
    vector<int> indeg(vertices, 0);

    for (int i=0; i<edges; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i=0; i<vertices; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        count++;
        int x = q.front();
        q.pop();
        cout<<x<<' ';
        // x --> v
        for (auto it: adj[x]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return 0;
}