#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define F first
#define S second
 
const int MAXN = 1e6 + 10;
 
int n, q, a[MAXN], d[MAXN];
map<int, int> bad, good, type;
set<int> goods;
 
int sec[10];
bool check(int x){
	if (x <= 0) return false;
	if (bad[x])
		return false;
	if (good[x] < (int)goods.size())
		return false;
	return true;
}
 
void showAns(){
	if (goods.empty())
		cout << "-1\n";
	else{
		int id = *goods.begin();
		int sz = 0;
		if (check(a[id] + d[id]))
			sec[sz++] = a[id]+d[id];
		if (d[id] && check(a[id] - d[id]))
			sec[sz++] = a[id] - d[id];
		cout << sz << " ";
		sort(sec, sec + sz);
		for (int i = 0; i < sz; i++)
			cout << sec[i] << " ";
		cout << "\n";
	}
}
 
void add(int id){
	int x = a[id] - d[id], y = a[id] + d[id];
	if (type[id] == 1){
		bad[x]++;
		if (x^y)
			bad[y]++;
	}
	else if (type[id] == 2){
		good[x]++;
		if (x^y)
			good[y]++;
		goods.insert(id);
	}
}
 
void remove(int id){
	int x = a[id] - d[id], y = a[id] + d[id];
	if (type[id] == 1){
		bad[x]--;
		if (x^y)
			bad[y]--;
	}
	else if (type[id] == 2){
		good[x]--;
		if (x^y)
			good[y]--;
		goods.erase(id);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> d[i];
		type[i] = 3;
	}
 
	while (q--){
		int t, id; cin >> t >> id, id--;
		if (t < 3)
			t = 3 - t;
		if (type[id] != t){
			remove(id);
			type[id] = t;
			add(id);
		}
		showAns();
	}
	return 0;
}