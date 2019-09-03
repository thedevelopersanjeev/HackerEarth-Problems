#include<bits/stdc++.h>

vector<int> Solution::sieve(int n){

    vector<int> isprime(n + 1, true);
    isprime[1] = true;
    isprime[2] = true;
    for(int i = 2; i * i <= n; i++){
        if(isprime[i]){
            for(int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    vector<int> ans;
    for(int i = 2; i <= n; i++){
        if(isprime[i])
            ans.push_back(i);
    }
    return ans;
    
}
