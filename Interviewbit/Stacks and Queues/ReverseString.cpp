string Solution::reverseString(string s){

    int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++)
        st.push(s[i]);
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;

}
