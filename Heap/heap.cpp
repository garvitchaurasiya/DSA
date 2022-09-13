#include "bits/stdc++.h"
using namespace std;

/*
    Heap is a complete binary tree which comes with a heap order property.

    Complete Binary Tree:
        -> BT where every level is completely filled except the last level.
        -> Nodes always added from the left or Nodes always lean towards the left.
        -> Leaf Nodes are from (n/2+1) to n. If it is represented in a array of indexes from 1 to n.

    Heap Order Property:
        ->Min Heap:
            ->Parent is always smaller than its childrens.
        ->Max Heap:
            ->Parent is always greater than its childrens.

    Heapify: Algorithm to put a node at its right place in the complete binary tree so that it can become heap.

*/

class heap{
    public:
    
    int arr[100];
    int size=0;
    // heap(){
        // size=0;
        // arr[0]=-1;
    // }

    void insert(int val){
        size++;
        int index = size;
        arr[size] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent], arr[index]);   
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<' ';
        }cout<<endl;
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        //take root node to its correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }

        }

    }

};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = i*2 + 1;
    if(left<=n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

signed main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 49, 53, 50, 52, 55};
    int n = 5;
    for(int i=n/2; i>=1; i--){
        heapify(arr, n, i);
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;

    return 0;
}