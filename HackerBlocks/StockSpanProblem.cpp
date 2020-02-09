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
		vector<long long> span(n, 1);
		stack<long long> st;
		st.push(0);
		for(long long i = 1; i < n; i++){
			while(!st.empty() && arr[st.top()] <= arr[i])
				st.pop();
			if(st.empty())
				span[i] = i + 1;
			else 
				span[i] = i - st.top();
			st.push(i);
		}
		for(auto ans : span)
			cout <<ans <<" ";
		cout <<"\n";
	}
    return 0;
}
