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
	long long n;
	cin >>n;
	vector<long long> arr(n);
	for(long long i = 0; i < n; i++)
		cin >>arr[i];
	if(n % 2 == 1)
		cout <<arr[n/2] <<"\n";
	else 
		cout <<arr[(n/2) - 1] <<"\n";
    return 0;
}
