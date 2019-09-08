#include<bits/stdc++.h>

// return (1/n) % m
int invNum(int n, int m){
    int ans = 1, base = n;
    int power = m - 2;
    while (power > 0) {
        if (power == 1) {
            return (ans * base) % m;
        }
        if (power % 2 == 0) {
            base = (base * base) % m;
            power /= 2;
        } else {
            ans = (ans * base) % m;
            power--;
        }
    }
    return ans;
}

int Solution::findRank(string s){

    int n = s.size();
    const int mod = 1000003;
    // map to store the frequencies of characters of the string
    unordered_map<char, int> mp;
    for(int i = 0; i < n; i++)
        mp[s[i]]++;
    // it will contain i! % mod
    vector<int> fact;
    fact.push_back(1);
    for(int i = 1; i <= n; i++)
        fact.push_back((fact[i-1] * i) % mod);
    int rank = 1;
    for(int i = 0; i < n; i++){
        int rem = n - i - 1;
        int less = 0;
        for(char ch = 'a'; ch < s[i]; ch++){
            if(mp[ch] == 0)
                continue;
            mp[ch]--;
            int temp = fact[rem];
            for(auto ele : mp){
                if(ele.second <= 1)
                    continue;
                temp = (temp * invNum(fact[ele.second], mod)) % mod;
            }
            mp[ch]++;
            less = (less + temp) % mod;
        }
        rank = (rank + less) % mod;
        mp[ch]--;
    }
    return rank;

}
