// Prims Algorithm is another algorithm for getting a Minimum Spanning Tree (MST) which is based on Greedy Method.

// 4 5
// 0 1 10
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40
// 0

#include "bits/stdc++.h"
using namespace std;

const int N = 1e6;
// vector<vector<int>> adj(N);
vector<vector<int>> adj[N]; // This is a vector of vector of array which is 3D. 2 vectors for adjacency list and we used array instead of pair to avoid writing .first .second
vector<bool> vis(N, false);
vector<int> dis(N, 1e9); // We are intializing the minimum distance vector to infinity as we want minimum values.

int cost = 0;

void primsMST(int source){
    
    set<vector<int>> s; // A set is used here because by-default a set is always sorted.
    dis[source] = 0; // distance from source to source is 0.
    s.insert({0, source}); // we have inserted weight first ( w-->u ) because we want to get sorted set here with respect to first element.
    
    while(!s.empty()){
        auto x = *(s.begin()); // "s.begin()" is a iterator pointing to the first element of the set and " *(s.begin()) " will give the value stored at the poiting address. The "auto" keyword is used to automatic assign the datatype as the value is of x would be vector.
        s.erase(x);
        
        int weight = x[0];
        int vertex = x[1];

        vis[vertex] = true;
        cost += weight; // We are directly adding the weight to our cost variable because we know the value of first element of the set would have minimum weight as it is sorted.

        for (auto it: adj[vertex]){ // Iterate over the adjacency list to cover all elements.
            // it[0] is a vertex as we have pushed {u, w}, {v, w} in the adj list.
            int v = it[0];
            int w = it[1];
            if(vis[v]){ // Do a dry run.
                continue;
            }
            if(dis[v] > w){ // We will update the value in set as well as dis vector.
                s.erase({dis[v], v});
                dis[v] = w;
                s.insert({w, v});
            }
        }

    }

}

int main(){

    int n, m; cin>>n>>m;

    for (int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    int source; cin>>source;
    primsMST(source);

    cout<<cost<<endl;

    return 0;
}