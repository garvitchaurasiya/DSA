// We can't store names of the set in computer so we make leader/parent element for that set.

// We have three approaches for DSU.

// 1. O(N) : Just "return find_set(parent[v])" here we will make chains which will increase the height of our tree and hence increses the time complexity. The chain would be like =>   3->5->1->2  Here the parent of 3 is 5, parent of 5 is 1, parent of 1 is 2. But we care only of the leader of the set which is 2.

// 2. O(log(N)) : By putting "return parent[v] = find_set(parent[v])" we will not make chains here instead of 3->5->1->2 we will make a tree where the leader would be the direct parent of the elements like 3->2, 5->2, 1->2, 2->2. Here the maximum height of the tree would we log(N) that's why complexity is O(logN).

// 3. Union By Rank/Size O(1) : By putting these statements "if(size[a] < size[b])  swap(a, b); size[a] += size[b];" we are appending the small tree to the largert tree to make the operations minimum and by doing that we will get our answer in atmost 4 steps which is constant.

#include "bits/stdc++.h"
using namespace std;

const int N = 1e6;
vector<int> parent(N);
vector<int> size(N);

void make (int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
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

    

    return 0;
}