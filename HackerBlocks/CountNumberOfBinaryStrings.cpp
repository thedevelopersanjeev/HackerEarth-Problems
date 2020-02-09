/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

long long findCount(long long n){
	if(n < 3)
		return n + 1;
	vector<long long> arr(n + 1);
	arr[1] = 2;
	arr[2] = 3;
	for(long long i = 3; i <= n; i++)
		arr[i] = arr[i-1] + arr[i-2];
	return arr[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long t, n;
	cin >>t;
	while(t--){
		cin >>n;
		cout <<findCount(n) <<"\n";
	}
    return 0;
}
