#include<bits/stdc++.h>
using namespace std;

long solve(long n){
    vector<int> digits;
    long x = n;
    while(x){
        digits.push_back(x%10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    long greater = -1;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] % 2 != 0){
            greater = i;
            break;
        }
    }
    if(greater == -1)
        return 0;
    long modn = 0;
    for(int i = greater; i < digits.size(); i++)
        modn = modn*10 + digits[i];
    long tarn = digits[greater] - 1;
    for(long i = greater+1; i < digits.size(); i++)
        tarn = tarn*10 + 8;
    if(digits[greater] == 9)
        return modn - tarn;
    else{
        long tar = digits[greater] + 1;
        for(long i = greater+1; i < digits.size(); i++)
            tar *= 10;
        return min(modn - tarn, tar - modn);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long t, n;
    cin >>t;
    for(int i = 1; i <= t; i++){
        cin >>n;
        cout <<"case #" <<i <<": " <<solve(n) <<"\n";
    }
    return 0;
}