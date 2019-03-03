#include<bits/stdc++.h>
using namespace std;

vector<int> X[200005];
int lca[18][200005], level[200005];

void dfs(int i, int par, int lvl){
    lca[0][i] = par;
    level[i] = lvl;

    for(auto x : X[i])
        if(x != par)
            dfs(x, i, lvl+1);
}

int getDist(int a, int b)
{
	return level[a] + level[b] - 2 * level[getLCA(a, b)];
}
int getNode(int a, int d)
{
	for(int i=0; i<18; i++)
		if(d & (1<<i))
			a = lca[i][a];
	
	return a;
}
int getCenter(int a, int b)
{
	int dist = getDist(a, b);
	int c = getLCA(a, b);
	
	if(level[a] - level[c] < level[b] - level[c])
		swap(a, b);
	
	if(dist % 2 == 0)
		return getNode(a, dist/2);
	
	return min(getNode(a, dist/2), getNode(a, dist/2+1));
}

int getLCA(int a, int b)
{
	if(level[a] > level[b])
		swap(a, b);
	
	int dist = level[b] - level[a];
	for(int i=17; i>=0; i--)
		if(dist & (1<<i))
			b = lca[i][b];
	
	if(a == b)
		return a;
	
	for(int i=17; i>=0; i--)
		if(lca[i][a] != lca[i][b])
			a = lca[i][a], b = lca[i][b];
	
	return lca[0][a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, u, v;
    cin >>n;
    for(int i = 1; i < n; i++){
        cin >>u >>v;
        X[u].push_back(v);
        X[v].push_back(u);
    }
    dfs(1, 0, 1);
    for(int i = 1; i < 18; i++)
        for(int j = 1; j <= n; j++)
            lca[i][j] = lca[i-1][lca[i-1][j]];
    int a, b;
	cin >> a;
	b = a;
	cout << a << " ";
	
	int diameter = 0;
	
	for(int i=2; i<=n; i++){
		int c;
		cin >> c;
		
		int lenA = getDist(a, c);
		int lenB = getDist(b, c);
		
		if(lenA < lenB)
			swap(lenA, lenB), swap(a, b);
		
		if(lenA > diameter)
			diameter = lenA, b = c;
		
		cout << getCenter(a, b) << " ";
	}
    return 0;
}