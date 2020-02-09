/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

long long findMinimumJumps(vector<long long> &arr){
	long long n = arr.size();
	if(n <= 1)
		return 0;
	long long ans = 1;
	long long x = arr[0], y = arr[0];
	for(long long i = 1; i < n; i++){
		if(i == n - 1)
			return ans;
		x = max(x, i + arr[i]);
		y--;
		if(y == 0){
			ans++;
			y = x - i;
		}
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long t, n;
	// cin >>t;
	t = 1;
	while(t--){
		cin >>n;
		vector<long long> arr(n);
		for(long long i = 0; i < n; i++)
			cin >>arr[i];
		cout <<findMinimumJumps(arr) <<"\n";
	}
    return 0;
}
