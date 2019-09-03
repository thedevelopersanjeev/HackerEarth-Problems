vector<int> Solution::wave(vector<int> &arr){

    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = 0; i < n - 1; i += 2)
        swap(arr[i], arr[i+1]);
    return arr;

}
