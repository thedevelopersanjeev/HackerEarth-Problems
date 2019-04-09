#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        int ans = 1;
        for(int i = 1; i <= n; i++)
            ans = ans * i / __gcd(ans, i);
        cout <<ans <<"\n";
    }
    return 0;
}