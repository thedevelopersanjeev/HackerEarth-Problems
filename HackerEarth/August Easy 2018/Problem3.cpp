#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long t, p, i, j, k, l, n, m;
    cin >>t;
    while(t--){
        cin >>n >>p;
        l = n*(n+1);
        l = l/2;
        k = p%l;
        
        bool an=false;
        long double low=0,high = 1,mid;
        for(i=0;i<20;++i){
            mid = (low+high)/2.;
            long long sum=0;
            for(j=1;j<=n;++j){
                sum+=mid*j;
            }
            if(sum<k)
                low = mid;
            else if(sum>k)
                high = mid;
            else
                an=true;
        }
        if(an)
            cout<<p/l<<"\n";
        else
        	cout<<-1<<"\n";
        
    }
    return 0;
}