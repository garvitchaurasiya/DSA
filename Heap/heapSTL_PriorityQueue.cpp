#include "bits/stdc++.h"
using namespace std;
/*
    Heap-STL:
        -> Priority queue.
        -> Priority queue is by default a max heap.
    
*/
signed main(){

    // Heap STL:

    priority_queue<int> pq;
    pq.push(3);
    pq.push(9);
    pq.push(1);
    pq.push(5);

    pq.top(); // Max-heap got the maximum element at the top.

    // Min Heap STL:

    priority_queue<int, vector<int>, greater<int> > minHeap;

    return 0;
}