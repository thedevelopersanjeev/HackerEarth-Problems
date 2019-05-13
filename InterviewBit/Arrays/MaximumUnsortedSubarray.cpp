vector<int> Solution::subUnsort(vector<int> &arr) {
    int i = 0, j = arr.size()-1;
    while(arr[i+1] >= arr[i])
        i++;
    while(arr[j-1] <= arr[j])
        j--;
    int mi = INT_MAX, ma = INT_MIN;
    vector<int> ans;
    if(i >= j){
        ans.push_back(-1);
        return ans;
    }
    for(int k = i; k <= j; k++){
        mi = min(mi, arr[k]);
        ma = max(ma, arr[k]);
    }
    for(int k = 0; k < i; k++){
        if(arr[k] > mi){
            i = k;
            break;
        }
    }
    for(int k = arr.size()-1; k > j; k--){
        if(arr[k] < ma){
            j = k;
            break;
        }
    }
    ans.push_back(i);
    ans.push_back(j);
    return ans;
}