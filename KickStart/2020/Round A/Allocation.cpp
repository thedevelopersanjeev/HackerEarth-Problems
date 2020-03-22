/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target ("sse4")
#pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define deb(x) cout << #x << " is " << x << "\n";

using namespace std;
using namespace __gnu_pbds;

const double PI = 2 * acos(0.0);
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t, n, b;
	cin >>t;
	for(long long i = 1; i <= t; i++) {
		cin >>n >>b;
		vector<long long> arr(n);
		for(long long i = 0; i < n; i++)
			cin >>arr[i];
		sort(arr.begin(), arr.end());
		long long curr = 0LL;
		long long ans = 0LL;
		long long j = 0LL;
		while(j < n && curr <= b) {
			if(curr + arr[j] <= b){
				ans++;
			}
			curr += arr[j];
			j++;
		}
		cout <<"Case #" <<i <<": " <<ans <<"\n";
	}
	return 0;
}
