vector<int> Solution::solve(vector<int> &A, int B) {

    vector<int> ans(A.size());
    stack<int> temp;
    int i = 0;
    while(B--){
        temp.push(A[i]);
        i++;
    }
    while(i < A.size()){
        ans[i] = A[i];
        i++;
    }
    i = 0;
    while(!temp.empty()){
        ans[i] = temp.top();
        temp.pop();
        i++;
    }
    return ans;
    
}