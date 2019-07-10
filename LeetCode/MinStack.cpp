class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> mainstack;
    stack<int> minstack;
    MinStack() {
    
        while(!mainstack.empty())
            mainstack.pop();
        while(!minstack.empty())
            minstack.pop();
        
    }
    
    void push(int x) {
        if(minstack.empty()){
        mainstack.push(x);
        minstack.push(x);
    }
    else{
        int temp = minstack.top();
        if(x < temp){
            minstack.push(x);
            mainstack.push(x);
        }
        else{
            minstack.push(temp);
            mainstack.push(x);
        }
    }
    }
    
    void pop() {
        if(!mainstack.empty()){
        mainstack.pop();
        minstack.pop();
    }
    }
    
    int top() {
        if(mainstack.empty())
        return -1;
    return mainstack.top();
    }
    
    int getMin() {
        if(minstack.empty())
        return -1;
    return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */