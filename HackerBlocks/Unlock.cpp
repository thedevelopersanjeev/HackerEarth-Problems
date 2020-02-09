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
	long long k, n;
	cin >>n >>k;
	vector<long long> arr(n);
	for(long long i = 0; i < n; i++)
		cin >>arr[i];
	long long i = 0;
	while(i < n && k > 0){
		if(arr[i] != n - i){
			long long j = i + 1;
			while(j < n && arr[j] != n - i)
				j++;
			swap(arr[i], arr[j]);
			k--;
		}
		i++;
	}
	for(auto ele : arr)
		cout <<ele <<" ";
    return 0;
}
