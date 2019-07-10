stack<int> mainstack;
stack<int> minstack;

MinStack::MinStack() {
    while(!mainstack.empty())
        mainstack.pop();
    while(!minstack.empty())
        minstack.pop();
}

void MinStack::push(int x) {
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

void MinStack::pop() {
    if(!mainstack.empty()){
        mainstack.pop();
        minstack.pop();
    }
}

int MinStack::top() {
    if(mainstack.empty())
        return -1;
    return mainstack.top();
}

int MinStack::getMin() {
    if(minstack.empty())
        return -1;
    return minstack.top();
}

