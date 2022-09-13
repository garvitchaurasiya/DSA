// Ques. From a source vertex v, find the shortes distance to all other nodes in the graph.

// => What makes Bellman Ford Algorithm better than Dijkstra:
// 1. It will work for negative edges and negative cycles.
// 2. It can detect negative cycles as well. // Bellman gives the answer in maximum n-1 passes if it doesn't give that means we are stuck in a negative cycles and hence this is how it detects.

// In Bellman Ford we have to relax every edge n-1 number of times.
// Relax means find minimum for that node.

// 5 8
// 1 2 3
// 3 2 5
// 1 3 2
// 3 1 1
// 1 4 2
// 0 2 4
// 4 3 -3
// 0 1 -1
// 0

#include "bits/stdc++.h"
using namespace std;

const int N = 1e6+2;
vector<int> dis(N, 1e9);

void Bellman(int source, int n, vector<vector<int>> edges){
    dis[source] = 0;
    for (int i=0; i<n-1; i++){
        for (auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dis[v] = min(dis[v], w + dis[u]);
        }
    }
}

int main(){

    int n, m; cin>>n>>m;
    vector<vector<int>> edges;

    for (int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
    }
    int source; cin>>source;
    Bellman(source, n, edges);
    for (int i=0; i<n; i++){
        cout<<dis[i]<<' ';
    }


    return 0;
}