int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(A[i]){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    temp.push_back(A[i] * (A[j] + A[k]));
                }
            }
        }
    }
    int ans = 0;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                int val = A[i]*A[j] + A[k];
                int incr = upper_bound(temp.begin(), temp.end(), val) - lower_bound(temp.begin(), temp.end(), val);
                ans = (ans + incr) % 1000000007;
            }
        }
    }
    return ans;
}
