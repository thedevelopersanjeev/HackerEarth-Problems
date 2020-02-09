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
	long long n, q, ele;
	cin >>n;
	vector<long long> arr(n);
	for(long long i = 0; i < n; i++)
		cin >>arr[i];
	cin >>q;
	while(q--){
		cin >>ele;
		auto lo = lower_bound(arr.begin(), arr.end(), ele) - arr.begin();
		auto hi = upper_bound(arr.begin(), arr.end(), ele) - arr.begin();
		if(binary_search(arr.begin(), arr.end(), ele))
			cout <<lo <<" " <<hi - 1 <<"\n";
		else 
			cout <<-1 <<" " <<-1 <<"\n";
	}
    return 0;
}
