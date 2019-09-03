#include<bits/stdc++.h>

vector<int> Solution::primesum(int n){

    vector<bool> isprime(n + 1, true);
    isprime[1] = true;
    isprime[2] = true;
    for(int i = 2; i * i <= n; i++){
        if(isprime[i]){
            for(int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++){
        if(isprime[i] && isprime[n - i]){
            return {min(i, n - i), max(i, n - i)};
        }
    }

}
