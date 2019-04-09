#include<bits/stdc++.h>
using namespace std;

bool isPrime(long n){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    long n;
    cin >>t;
    while(t--){
        cin >>n;
        long x = n - 1;
        while(1){
            if(n%x == 0 && isPrime(x)){
                cout <<x <<"\n";
                break;
            }
            x = x - 1;
        }
    }
    return 0;
}