int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    int ans = 0, temp = 0; 
    for (int i = 0; i < n; ++i){
        temp = max(temp, arr[i]); 
        if(temp == i) 
            ans++; 
    }
    return ans; 
}
