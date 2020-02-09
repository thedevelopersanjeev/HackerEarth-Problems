/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

long long patternMatching(string s, string p, int n, int m){
	if(n == 0 && m == 0)
		return 1;
	if(n != 0 && m == 0)
		return 0;
	vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
	dp[0][0] = 1;
	for(long long j = 1; j <= m; j++)
		if(p[j-1] == '*')
			dp[0][j] = dp[0][j-1];
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j <= m; j++){
			if(p[j-1] == '?' || p[j-1] == s[i-1])
				dp[i][j] = dp[i-1][j-1];
			else if(p[j-1] == '*')
				dp[i][j] = dp[i-1][j] | dp[i][j-1];
			else 
				dp[i][j] = 0;
		}
	}
	return dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string s, p;
	cin >>s >>p;
	long long n = s.size();
	long long m = p.size();
	cout <<patternMatching(s, p, n, m);
    return 0;
}
