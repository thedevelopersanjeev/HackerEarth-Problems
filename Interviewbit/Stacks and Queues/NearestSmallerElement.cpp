vector<int> Solution::prevSmaller(vector<int> &arr){

    stack<int> st;
    vector<int> ans;
    for(auto ele : arr){
        // remove elements while elements to the left are greater in value
        while(!st.empty() && st.top() >= ele)
            st.pop();
        if(!st.empty())
            ans.push_back(st.top());
        else 
            ans.push_back(-1);
        st.push(ele);
    }
    return ans;

}