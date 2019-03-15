#include<bits/stdc++.h>
using namespace std;

int main(){
	int tn;
	cin>>tn;
	for(int tc=1;tc<=tn;tc++){
		int n,k;
		cin>>n>>k;
		double v[n];
		double vs[n+1];
		vs[0]=0;
		for(int i=0;i<n;i++){ 
			scanf("%lf",v+i);
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			vs[i+1]=vs[i]+v[i];
		}
		double e=0;
		for(int i=0;i<k+1;i++){
			int x = upper_bound(v,v+n,e)-v;
			e=(x*e+vs[n]-vs[x])/(double)n;
		}
		cout<<"Case #"<<tc<<": "<<setprecision(7)<<fixed<<e<<"\n";
	}
	return 0;
}