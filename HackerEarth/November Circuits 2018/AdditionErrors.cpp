#include<bits/stdc++.h>
using namespace std;

long long xSum(long long n, long long m){ 
    long long res = 0;
    long long multiplier = 1; 
    long long bit_sum; 
    while (n || m){ 
        bit_sum = (n % 10) + (m % 10);
        bit_sum %= 10;
        res = (bit_sum * multiplier) + res; 
        n /= 10; 
        m /= 10; 
        multiplier *= 10; 
    } 
    return res; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    long long n, m;
    cin >>t;
    while(t--){
        cin >>n >>m;
        cout <<abs((m+n)-xSum(n, m)) <<"\n";
    }
    return 0;
}