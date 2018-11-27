#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        long long int d, a, m, b, x, w, mon = 0;
        cin >>d >>a >>m >>b >>x;
        if(x <= d){
            cout<<mon<<endl;
            break;
        }
        x -= d;
        if((x)%(a*m +b) == 0){
            mon = ((x)/(a*m +b))*(m+1);
        }
        else{
            w = (x)%(a*m +b);
            mon = ((x)/(a*m +b))*(m+1);
            mon = mon+w/a;
            w = w%a;
            if(w>0)
                mon++;
        }
        cout <<mon <<endl;
    }
    return 0;
}