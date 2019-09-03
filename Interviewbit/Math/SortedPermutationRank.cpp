#include<bits/stdc++.h>

int f(int n, int mod){
    if(n < 2)
        return 1;
    return (n * f(n - 1, mod)) % mod;
}

int Solution::findRank(string s){

    int n = s.size();
    const int mod = 1000003;
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int cnt = 0;
        for(int j = i + 1; j < n; j++){
            if(s[j] < s[i])
                cnt++;
        }
        int fact = f(n - i - 1, mod);
        ans = (ans + (cnt * fact) % mod) % mod;
    }
    return (ans + 1) % mod;

}
