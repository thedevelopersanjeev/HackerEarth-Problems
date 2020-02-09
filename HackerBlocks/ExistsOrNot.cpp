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
	long long t, n, q, ele;
	cin >>t;
	while(t--){
		cin >>n;
		vector<long long> arr(n);
		for(long long i = 0; i < n; i++)
			cin >>arr[i];
		sort(arr.begin(), arr.end());
		cin >>q;
		while(q--){
			cin >>ele;
			if(binary_search(arr.begin(), arr.end(), ele))
				cout <<"Yes\n";
			else 
				cout <<"No\n";
		}
	}
    return 0;
}
