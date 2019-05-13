vector<int> Solution::solve(vector<int> &arr) {
    int j = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] != 0)
            swap(arr[j++], arr[i]);
    }
    return arr;
}
