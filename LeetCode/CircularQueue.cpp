class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int> q;
    int n;
    
    MyCircularQueue(int k) {
        n = k;
        q.clear();
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(q.size() == n)
            return false;
        q.push_back(value);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(q.empty())
            return false;
        q.erase(q.begin());
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return q.empty() ? -1 : q.front();
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return q.empty() ? -1 : q.back();
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return q.empty();
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return q.size() == n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */