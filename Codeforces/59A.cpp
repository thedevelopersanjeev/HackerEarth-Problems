/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >>s;
    int n = s.size();
    int lo = 0, hi = 0;
    for(int i = 0; i < n; i++){
        if(islower(s[i]))
            lo++;
        else
            hi++;
    }
    if(hi > lo){
        for(int i = 0; i < n; i++){
            cout <<(char)toupper(s[i]);
        }
    }
    else{
        for(int i = 0; i < n; i++)
            cout <<(char)tolower(s[i]);
    }
    return 0;
}