vector<int> Solution::subUnsort(vector<int> &arr){

    int left = -1, right = -1;
    int temp = arr[0];
    int n = arr.size();
    for(int i = 1; i < n; i++){
        if(temp > arr[i])
            right = i;
        temp = max(temp, arr[i]);
    }
    temp = arr[n-1];
    for(int i = n - 1; i >= 0; i--){
        if(temp < arr[i])
            left = i;
        temp = min(temp, arr[i]);
    }
    if(left == -1)
        return {-1};
    else 
        return {left, right};

}
