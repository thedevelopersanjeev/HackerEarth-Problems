#include <bits/stdc++.h>
using namespace std;
int ans[200005];
 
const int N = 500000;
const int ln = 20;
int depth[N+5], par[ln][N+5];
vector<int> g[N+5];
void dfs(int u, int p, int d){
	par[0][u] = p;
	depth[u] = d+1;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		if(v == p) continue;
		dfs(v, u, d+1);
	}
}
int LCA(int a, int b){
	if(depth[b] > depth[a]) swap(a, b);
	int diff = depth[a] - depth[b];
	for(int i=ln-1;i>=0;i--){
		if((diff>>i)&1) a = par[i][a];
	}
	if(a == b) return a;
	for(int i=ln-1;i>=0;i--){
		if(par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
	}
	return par[0][a];
}
int dist(int a, int b){
	return depth[a] + depth[b] - 2*depth[LCA(a, b)];
}
 
int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i=1;i<=n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1, 0, 0);
	for(int j=1;j<ln;j++){
		for(int i=1;i<=n;i++){
			if(par[j-1][i] != 0) par[j][i] = par[j-1][par[j-1][i]];
		}
	}
	while(q--){
		int k;
		scanf("%d", &k);
		vector<int> v;
		for(int i=0;i<k;i++){
			int x;
			scanf("%d", &x);
			v.emplace_back(x);
		}
		int idx = 0;
		int cur = 0;
		for(int i=1;i<k;i++){
			int d = dist(v[0], v[i]);
			if(d >= cur) idx = i, cur = d;
		}
		int ans = 0;
		for(int i=0;i<k;i++){
			ans = max(ans, dist(v[idx], v[i]));
		}
		printf("%d\n", ans);
	}
}