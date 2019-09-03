#include<bits/stdc++.h>

int f(int n, int mod){
    if(n < 2)
        return 1;
    return (n * f(n - 1, mod)) % mod;
}

int Solution::findRank(string s){

    int n = s.size();
    const int mod = 1000003;
    for(int i = 0; i < n - 1; i++){
        int cnt = 0;
        map<char, int> mp;
        for(int j = i + 1; j < n; j++){
            if(s[j] < s[i])
                cnt++;
            mp[s[j]]++;
        }
        int temp = f(n - i - 1, mod);
        for(auto ele : mp)
            temp /= f(ele.second, mod);
        ans = (ans + (cnt * temp) % mod) % mod;
    }
    return ans;

}
