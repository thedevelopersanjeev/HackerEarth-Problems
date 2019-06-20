vector<int> Solution::solve(vector<int> &A, int B) {

    int curr = A[0];
    int n = A.size();
    int i = 0;
    for(int j = 1; j <= n; j++){
        if(curr == B){
            // found answer
            vector<int> ans;
            for(int k = i; k < j; k++)
                ans.push_back(A[k]);
            return ans;
        }
        if(j < n)
            curr += A[j];
        while(curr > B && i < j){
            curr -= A[i];
            i++;
        }
    }
    vector<int> ans(1, -1);
    return ans;
    
}