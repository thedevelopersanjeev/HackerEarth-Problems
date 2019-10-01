int Solution::braces(string s){

    int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(s[i] != ')')
            st.push(s[i]);
        else{
            if(st.empty())
                return false;
            if(st.top() == ')')
                return true;
            int cnt = 0;
            while(!st.empty()){
                cnt++;
                char c = st.top();
                st.pop();
                if(c == '(')
                    break;
            }
            if(cnt < 3)
                return true;
        }
    }
    return false;

}
