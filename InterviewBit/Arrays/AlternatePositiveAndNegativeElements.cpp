void rotate(vector<int> &arr, int start, int end){
    int last = arr[end];
    for(int i = end - 1; i >= start; i--)
        arr[i+1] = arr[i];
    arr[start] = last;
}

bool isSignEqual(int x, int y){
    if(x < 0 && y < 0)
        return true;
    if(x >= 0 && y >= 0)
        return true;
    return false;
}

vector<int> Solution::solve(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) { 
        if(i%2 == 0 && arr[i] < 0) {
            int p = -1;
            for(int j = i + 1; j < n; j++)
                if(arr[j] >= 0){
                   p = j;
                   break;
                }
            if(p == -1)
                break;
            else
                rotate(arr, i, p);
        }
        else if(i%2 == 1 && arr[i] >= 0){
            int ni = -1;
            for(int j = i + 1; j < n; j++)
                if(arr[j] < 0){
                   ni = j;
                   break;
                }
            if(ni == -1)
                break;
            else
               rotate(arr, i, ni);
        }
    }
    if(n%2 == 0){
        for(int i = 0; i < n; i += 2)
            if(!isSignEqual(arr[i], arr[i+1]))
                swap(arr[i], arr[i+1]);
    }
    else{
        for(int i = 0; i < n - 1; i += 2)
            if(!isSignEqual(arr[i], arr[i+1]))
                swap(arr[i], arr[i+1]);
    }
    return arr;
}