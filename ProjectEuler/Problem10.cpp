#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long max = 10000001;
    bool prime[max];
    long sum[max];
    memset(prime, true, sizeof(prime));
    for(long p = 2; p*p <= max-1; p++){
        if(prime[p]){
            for(long i = p*p; i <= max-1; i += p){
                prime[i] = false;
            }
        }
    }
    long temp = 0;
    for(long i = 2; i < max-1; i++){
        if(prime[i])
            temp += i;
        sum[i] = temp;
    }
    long t, n;
    cin >>t;
    while(t--){
        cin >>n;
        cout <<sum[n] <<"\n";
    }
    return 0;
}
