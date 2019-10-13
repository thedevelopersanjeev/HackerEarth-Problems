stack<int> st;
stack<int> minst;

MinStack::MinStack() {
    // clear both stacks
    while(!st.empty())
        st.pop();
    while(!minst.empty())
        minst.pop();
}

void MinStack::push(int x) {
    if(minst.empty() || x <= minst.top())
        minst.push(x);
    st.push(x);
}

void MinStack::pop() {
    if(st.empty())
        return;
    if(minst.top() == st.top()){
        minst.pop();
        st.pop();
    }
    else{
        st.pop();
    }
}

int MinStack::top() {
    if(st.empty())
        return -1;
    return st.top();
}

int MinStack::getMin() {
    if(minst.empty())
        return -1;
    return minst.top();
}

