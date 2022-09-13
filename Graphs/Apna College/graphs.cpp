#include "bits/stdc++.h"
using namespace std;
/*
    In lehman terms Graph is a type of data structure which is basically the combination of nodes and edges.
*/

class graph{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

};
signed main(){

    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0; i<m; i++){
        int u, v; 
        cin>>u>>v;
        // Creating an undirected graph.
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    return 0;
}