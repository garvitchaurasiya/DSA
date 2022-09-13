// Ques. Given a weighted graph. Find the single source shortest path from a vertex u to all the vertices in the graph. If the node is unreachable, then print -1. 

// The weights of the edges must be positive as if it is positive our code will stuck in infinite loop.

// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1
// Output: 0 24 3 15

#include "bits/stdc++.h"
using namespace std;

const int N = 1e6+3;
vector<vector<int>> adj[N];
vector<int> dis(N, 1e9);

void dijkstra(int source){
    // Remember we have not created the array visited because we want to check all the possible cases that exists.
    dis[source] = 0;
    set<vector<int>> s;
    s.insert({0, source}); // We have inserted weight first ( w-->u ) because we want to get sorted set here with respect to first element.

    while(!s.empty()){
        auto x = *(s.begin());// "s.begin()" is a iterator pointing to the first element of the set and " *(s.begin()) " will give the value stored at the poiting address. The "auto" keyword is used to automatic assign the datatype as the value is of x would be vector.
        s.erase(x);

        int weight = x[0];
        int vertex = x[1];

        for (auto it: adj[vertex]){
            // it[0] is a vertex as we have pushed {u, w}, {v, w} in the adj list.
            int v = it[0];
            int w = it[1];

            if(dis[v] > dis[vertex] + w){ // "dis[vertex]" is the only difference in Dijkstra's and Prim's algorithms.
                s.erase({ dis[v], v });
                dis[v] = dis[vertex] + w;
                s.insert({ dis[vertex] + w, v });
            }
        }
    }
}

int main(){

    int n, m; cin>>n>>m;
    for (int i=0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source; cin>>source;
    dijkstra(source);

    for (int i=1; i<=n; i++){
        if(dis[i]<1e9){
            cout<<dis[i]<<' ';
        }
        else{
            cout<<-1<<' ';
        }
    }

    return 0;
}