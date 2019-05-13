vector<int> Solution::sieve(int A) {
    
    vector<int> ans;
    int isPrime[A+1];
    for(int i = 0; i <= A; i++)
        isPrime[i] = 1;
    for(int i = 2; i*i <= A; i++){
        if(isPrime[i] == 1){
            for(int j = i*i; j <= A; j += i)
                isPrime[j] = 0;
        }
    }
    for(int i = 2; i <= A; i++){
        if(isPrime[i] == 1)
            ans.push_back(i);
    }
    return ans;
}
