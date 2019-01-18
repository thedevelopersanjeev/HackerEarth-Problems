#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int p[200005], s[200005];
vector<pii> best;
int main(){
	int m;
	LL n, b;
	scanf("%lld%d%lld", &n, &m, &b);
	for(int i=1;i<=m-1;i++){
		scanf("%d", &p[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d", &s[i]);
	}
 
	LL buy = 0;
	LL mx = 0;
	for(int i=1;i<=m;i++){
		if(s[i]-buy > mx){
			best.push_back(pii(buy, s[i]-buy));
			mx = s[i]-buy;
		}
		buy += p[i];
	}
	for(int i=0;i<best.size();i++){
		if(i == best.size()-1){
			b += n*best[i].second;
		}
		else{
			LL nt = best[i+1].first;
			if(nt <= b) continue;
			else{
				LL diff = nt-b;
				LL cost = best[i].second;
				LL target = min((diff+cost-1)/cost, n);
				b += target*cost;
				n -= target;
			}
		}
	}
	printf("%lld\n", b);
}