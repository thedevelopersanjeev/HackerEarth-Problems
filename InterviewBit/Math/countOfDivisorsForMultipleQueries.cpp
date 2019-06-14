vector<int> Solution::solve(vector<int> &arr) {
    // build sieve
    vector<int> sieve(1001001);
    int n = sieve.size();
    for(int i = 1; i < n; i++)
        sieve[i] = i;
    for(int i = 2; i*i <= n; i++){
        if(sieve[i] != i)
            continue;
        for(int j = i*i; j < n; j += i)
            if(sieve[j] == j)
                sieve[j] = i;
    }
    vector<int> ans;
    for(auto ele : arr){
        int temp = 1; 
        while(sieve[ele] > 1){
            int count = 1, x = sieve[ele];
            while(sieve[ele] == x){
                count++;
                ele /= x;
            }
            temp *= count;
        }
        ans.push_back(temp);
    }
    return ans;
}