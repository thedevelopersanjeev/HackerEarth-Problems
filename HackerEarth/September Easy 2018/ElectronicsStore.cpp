#include <bits/stdc++.h>
#define long long long
using namespace std;
const int N = 301;
const long INF = 1e16+1;
 
int n, T, maxQ, Q[N], P[N], W[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> T;
	for(int i = 1; i <= n; i++) cin >> Q[i], maxQ = max(Q[i], maxQ);
	for(int i = 1; i <= n; i++) cin >> P[i];
	for(int i = 1; i <= n; i++) cin >> W[i];
	vector<long> dp(T + 1, 0);
	dp[0] = 0;
	for(int turn = 1; turn <= maxQ; turn++) {
		vector<long> tmp(T + 1, 0), actual(T + 1, 0); // has to be zero?
		tmp[0] = 0, actual[0] = 0;
		for(int i = 1; i <= n && 1ll * turn * 2 * i <= T; i++) if(Q[i] >= turn) {
			for(int j = T; j >= 0; j--) {
				if(j >= W[i]) tmp[j] = max(tmp[j - W[i]] + P[i], tmp[j]);
				if(j + 2*i <= T) actual[j + 2*i] = max(tmp[j], actual[j + 2*i]);
			}
		}
		for(int j = T; j >= 0; j--) {
			for(int x = 0; 1ll * x * turn <= T; x++) {
				if(j - x >= 0) dp[j] = max(dp[j - x] + actual[x], dp[j]);
			}
		}
	}
	for(int i = 1; i <= T; i++) cout << dp[i] << ' ';
}