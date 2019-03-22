#include<bits/stdc++.h>
using namespace std;

bool check(long x){
	if(x%9 == 0)
		return false;
	string y = to_string(x);
	if(y.find('9') != string::npos)
		return false;
	else
		return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	long f, l;
	cin >>t;
	for(int i = 1; i <= t; i++){
		cin >>f >>l;
		long ans = 0;
		for(int j = f; j <= l; j++){
			if(check(j))
				ans++;
		}
		cout <<"Case #" <<i <<": " <<ans <<"\n";
	}
	return 0;
}