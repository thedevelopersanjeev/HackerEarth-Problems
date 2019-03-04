#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long t, n, m, k;
	cin >>t;
	while(t--){
		cin >>n >>m >>k;
		vector<long> arr(n);
		for(long i = 0; i < n; i++)
			cin >>arr[i];
		arr.resize(n*m);
		for(long i = 1; i <= m; i++){
			long start = (i-1) * n;
			long end = i*n - 1;
			for(long j = start; j <= end; j++)
				arr[j] = arr[j+n-(i*n)]; 
		}
		for(long i = 1; i < n*m; i++)
			arr[i] += arr[i-1];
		long ans = 0;
		for(long i = 0; i < arr.size()-1; i++){
			for(long j = i+1; j < arr.size(); j++){
				if(arr[j] - arr[i] <= k)
					ans = (ans + 1)%1000000007;
			}
		}
		for(auto ele : arr)
			if(ele <= k)
				ans = (ans + 1)%1000000007;
		cout <<ans <<"\n";
	}
	return 0;
}