/**
 * Template for Contests
 *
 *  @author Sanjeev
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, l, r;
    cin >>t;
    while(t--){
        cin >>l >>r;
        long long ans = 0;
        for(long long i = l; i <= r; i++)
            ans ^= i;
        if(ans%2 == 0)
            cout <<"Even\n";
        else 
            cout <<"Odd\n";
    }
    return 0;
}