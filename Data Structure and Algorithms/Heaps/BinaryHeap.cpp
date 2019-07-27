// Implementation of Binary Heap
// MinHeap - A Node value is smaller than all of its children
// and this is true for all nodes.
// Smallest element is present at root node.
#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    private :
    // array to store the element's values
    vector<int> arr;
    // maximum possible size of heap
    int capacity;
    // current size of heap
    int heap_size;

    public :
    // constructor
    // builds a min heap with given max size
    MinHeap(int size){
        // current size of heap is 0 as there are no elements in it
        heap_size = 0;
        // assign maximum size
        capacity = size;
        // create an aaray of appropriate size
        arr.resize(size);
    }

    // get parent of given node
    int parent(int i){
        return (i - 1) / 2;
    }

    // get left child of given node
    int left(int i){
        return 2 * i + 1;
    }

    // get right index of given node
    int right(int i){
        return 2 * i + 2;
    }

    // Insert new node into the heap
    void insertKey(int val){
        // check if size is available
        if(heap_size == capacity){
            cout <<"\nOverflow! Max Heap Size Reached!\n";
            return;
        }
        // increase heap size and add new value in the end of heap
        heap_size++;
        // get the last index
        int last = heap_size - 1;
        // assign new value at last index
        arr[last] = val;
        // fix min heap property
        // bubble up the value till it violates min heap property
        while(last != 0 && arr[parent(last)] > arr[last]){
            swap(arr[parent(last)], arr[last]);
            last = parent(last);
        }
    }

    // update the value at index i to new value
    // assuming that the new value is smaller
    void decreaseKey(int i, int val){
        arr[i] = val;
        // fix min heap property
        // bubble up the new value till it violates min heap property
        while(i != 0 && arr[parent(i)] > arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // recursive method to heapify a subtree rooted at index i
    // this method assumes that i's children are already heapified
    void minHeapify(int i){
        // get index of left child
        int l = left(i);
        // get index of right child
        int r = right(i);
        // index containing smallest value
        int smallest = i;
        // check if smaller element is on left child
        if(l < heap_size && arr[l] < arr[i])
            smallest = l;
        // compare left child with right child for smaller element
        if(r < heap_size && arr[r] < arr[smallest])
            smallest = r;
        // if smaller element is one of left or right child
        // swap it with root and call minHeapify on that child recursively
        if(smallest != i){
            swap(arr[smallest], arr[i]);
            minHeapify(smallest);
        }
    }

    // remove minimum element(root) from the heap
    int extractMin(){
        // no elements present in the heap
        if(heap_size <= 0)
            return INT_MAX;
        // single element present in the heap
        if(heap_size == 1){
            heap_size--;
            return arr[0];
        }
        // store the minimum element in temporary variable
        int root = arr[0];
        // move last element to root node
        arr[0] = arr[heap_size-1];
        // decrease heap size as minimum element has been overwritten by last element
        heap_size--;
        // call heapify at root to maintain min heap property
        minHeapify(0);
        return root;
    }

    // deletes key at index i
    // decreases the key value to INT_MIN
    // and then calls extract min
    void deleteKey(int i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // return minimum element/root
    int getMin(){
        return arr[0];
    }

};

int main(){
    MinHeap heap(11);
    heap.insertKey(3);
    heap.insertKey(2);
    heap.deleteKey(1);
    heap.insertKey(15);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(45);
    cout <<heap.extractMin() <<" ";
    cout <<heap.getMin() <<" ";
    heap.decreaseKey(2, 1);
    cout <<heap.getMin() <<" \n";
    return 0;
}