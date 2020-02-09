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
		vector<int> arr(n);
		for(long long i = 0; i < n; i++)
			cin >>arr[i];
		unordered_map<long long, long long> mp;
		mp[0] = -1;
		long long len = 0, end = -1, sum = 0;
		for(long long i = 0; i < n; i++){
			// sum till ith index in sum
			if(arr[i] == 0)
				sum--;
			else 
				sum++;
			// if we have seen this sum before, there is a subarray with equal
			// number of zeros and ones
			if(mp.find(sum) != mp.end()){
				if(len < i - mp[sum]){
					// found a subarray of greater length
					len = i - mp[sum];
					end = i;
				}
			} 
			// else, put current sum into the map
			// along with its index
			else{
				mp[sum] = i;
			}
		}
		if(end != -1){
			cout <<end - len + 1 <<" " <<end <<"\n";
		}
		else{
			cout <<"None\n";
		}
	}
    return 0;
}
