/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	long long t, n;
	cin >>t;
	while(t--){
		cin >>n;
		vector<long long> arr(n);
		for(long long i = 0; i < n; i++)
			cin >>arr[i];
		vector<long long> left(n), right(n);
		left[0] = arr[0];
		right[n-1] = arr[n-1];
		for(long long i = 1; i < n; i++)
			left[i] = max(left[i-1], arr[i]);
		for(long long i = n - 2; i >= 0; i--)
			right[i] = max(right[i+1], arr[i]);
		long long ans = 0;
		for(long long i = 0; i < n; i++){
			long long height = min(left[i], right[i]);
			if(arr[i] < height)
				ans += (height - arr[i]);
		}
		cout <<ans <<"\n";
	}
    return 0;
}
