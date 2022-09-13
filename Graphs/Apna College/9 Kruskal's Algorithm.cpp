// Spanning Tree: Given an undirected and connected graph G(V, E), a spanning tree of the graph G is a tree that spans G (that is, it includes every vertex of G) and is a subgraph of G (every edge in the tree belongs to G).

// Cost of the spanning tree: The cost of the spanning tree is the sum of the weights of all the edges in the tree.

// There can be multiple spanning trees of a single graph.

// Minimum Spanning tree: A spanning tree where the cost is minimum amoung all the spanning trees.

// There can be multiple spanning trees too as the weights of egdes can shuffle until the overall cost is minimum.

// 8 9
// 1 2 5
// 2 3 6
// 4 3 2
// 1 4 9
// 3 5 5
// 5 6 10
// 6 7 7
// 7 8 1
// 8 5 1

#include "bits/stdc++.h"
using namespace std;

const int N = 1e6;
vector<int> parent(N);
vector<int> size(N);

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(parent[v]==v){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

int union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b){

        if(size[a] < size[b]){
            swap(a, b);
        }

        size[a] += size[b];
        
        parent[b] = a;
    }

}

int main(){

    for (int i=0; i<N; i++){
        make_set(i);
    }
    int n, m; cin>>n>>m;

    vector<vector<int>> edges;

    for (int i=0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        edges.push_back({w, u, v}); // Focus we have pushed weight first then vertices.
    }

    sort(edges.begin(), edges.end()); // We pushed weight first because this sort function sorts the 2d vector on behalf of the first element of our vectors. If we don't wanna do this we would have to specify a compare function as the third argument of sort function.

    int cost = 0;

    for (auto it: edges){
        int w = it[0];
        int u = it[1];
        int v = it[2];
        int a = find_set(u);
        int b = find_set(v);
        if(a==b){
            continue;
        }
        else{
            cout<<u<<' '<<v<<'\n';
            cost += w;
            union_set(a, b);
        }
    }
    cout<<cost<<endl;

    return 0;
}