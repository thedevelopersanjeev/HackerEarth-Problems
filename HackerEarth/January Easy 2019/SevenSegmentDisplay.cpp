#include<bits/stdc++.h>
using namespace std;

int a[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    a[0] = a[6] = a[9] = 6;
    a[1] = 2;
    a[2] = a[3] = a[5] = 5;
    a[4] = 4;
    a[7] = 3;
    a[8] = 7;
    int t;
    string n;
    cin >>t;
    while(t--){
        cin >>n;
        int match = 0;
        for(int i = 0; i < n.size(); i++){
            match += a[n[i] - '0'];
        }
        if(match % 2 == 1){
            cout <<"7";
            match -= 3;
        }
        while(match>=2){
            match -= 2;
            cout <<"1";
        }
        cout <<"\n";
    }
    return 0;
}