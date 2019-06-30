int Solution::solve(vector<int> &A) {

    set<int> st;
    
    for(auto ele : A)
        st.insert(ele);
        
    int count = 0;
        
    for(int i = 0; i < A.size(); i++){
        for(int j = i+1; j < A.size(); j++){
            if(st.find(A[i]+A[j]) != st.end())
                count++;
        }
    }
    
    return count;
    
}