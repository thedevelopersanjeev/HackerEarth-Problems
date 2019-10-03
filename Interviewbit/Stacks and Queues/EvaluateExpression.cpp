int Solution::evalRPN(vector<string> &arr){

    int n = arr.size();
    stack<string> st;
    for(int i = 0; i < n; i++){
        if(arr[i] == "+"){
            int op2 = stoi(st.top());
            st.pop();
            int op1 = stoi(st.top());
            st.pop();
            st.push(to_string(op1 + op2));
        }
        else if(arr[i] == "-"){
            int op2 = stoi(st.top());
            st.pop();
            int op1 = stoi(st.top());
            st.pop();
            st.push(to_string(op1 - op2));
        }
        else if(arr[i] == "*"){
            int op2 = stoi(st.top());
            st.pop();
            int op1 = stoi(st.top());
            st.pop();
            st.push(to_string(op1 * op2));
        }
        else if(arr[i] == "/"){
            int op2 = stoi(st.top());
            st.pop();
            int op1 = stoi(st.top());
            st.pop();
            st.push(to_string(op1 / op2));
        }
        else 
            st.push(arr[i]);
    }
    return stoi(st.top());

}
