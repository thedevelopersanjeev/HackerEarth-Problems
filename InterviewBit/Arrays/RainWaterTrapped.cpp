int Solution::trap(const vector<int> &A) {
    // using two pointer approach
    int n = A.size();
    // left pointer
    int l = 0;
    // right pointer
    int r = n - 1;
    int l_max = A[l];
    int r_max = A[r];
    int ans = 0;
    while(l < r){
        if(A[l] < A[r]){
            if(A[l] >= l_max)
                l_max = A[l];
            else
                ans += (l_max - A[l]);
            l++;
        }
        else{
            if(A[r] >= r_max)
                r_max = A[r];
            else
                ans += (r_max - A[r]);
            r--;
        }
    }
    return ans;
}
