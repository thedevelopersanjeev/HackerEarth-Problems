void Solution::nextPermutation(vector<int> &arr){
    
    // 1. Find highest index i such that arr[i] < arr[i+1]
    int imax = -1;
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        if(arr[i] < arr[i+1])
            imax = i;
    }
    // If no such i exists, given permutation is last permutation
    if(imax == -1){
        sort(arr.begin(), arr.end());
        return;
    }
    // 2. Find highest j such that j > imax and arr[j] > arr[imax]
    int jmax = imax + 1;
    for(int j = imax + 1; j < n; j++){
        if(arr[j] > arr[imax]){
            jmax = j;
        }
    }
    // 3. swap arr[imax] and arr[jmax]
    swap(arr[imax], arr[jmax]);
    // 4. Reverse all elements after index imax
    reverse(arr.begin() + imax + 1, arr.end());

}
