int Solution::repeatedNumber(const vector<int> &arr){

    int n = arr.size();
    // its 99.99% sure to get our answer in 23 tries atmost
    for(int i = 0; i < 23; i++){
        // pick any random element from the array
        int index = rand() % n;
        int ele = arr[index];
        int cnt = 0;
        // check its count in the array
        for(int i = 0; i < n; i++){
            if(arr[i] == ele)
                cnt++;
        }
        // if it becomes > n/3, we got our answer
        if(cnt > n/3)
            return ele;
    }
    // if control reaches here, we didn't find out answer...
    return -1;
    
}
