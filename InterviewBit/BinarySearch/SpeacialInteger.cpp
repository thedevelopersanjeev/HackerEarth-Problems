int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int start = 0, end = n, ans = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        int temp = 0;
        for(int i = 0; i < mid; i++){
            temp += A[i];
            if(temp > B)
                break;
        }
        if(temp <= B){
            for(int i = mid; i < n; i++){
                temp -= A[i-mid];
                temp += A[i];
                if(temp > B)
                    break;
            }
        }
        if(temp > B){
            end = mid - 1;
        }
        else{
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}
