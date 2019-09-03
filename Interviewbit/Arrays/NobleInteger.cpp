int Solution::solve(vector<int> &arr){

    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int j = i + 1;
        while(arr[j] == arr[i])
            j++;
        int count = 0;
        while(j < n){
            j++;
            count++;
        }
        if(count == arr[i])
            return 1;
    }
    return -1;

}
