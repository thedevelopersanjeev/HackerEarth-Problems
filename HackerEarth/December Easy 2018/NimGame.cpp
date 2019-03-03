#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<int> A, B;
long long dp[69][2][2][2][2][2];
void getNum(long long N, vector<int> &X)
{
	X.clear();
	
	while(N)
		X.push_back(N%2), N /= 2;
}
long long solve(int indx, int lo1, int lo2, int carry1, int carry2, int is_zero)
{
	if(indx == A.size())
	{
		// (no more carrys are allowed) && (y is strictly less 
		// than x) && (y is not 0)
		return (carry1 + carry2 == 0 && lo2 == 1 && is_zero == 1);
	}
	
	if(dp[indx][lo1][lo2][carry1][carry2][is_zero] != -1)
		return dp[indx][lo1][lo2][carry1][carry2][is_zero];
	
	long long ans = 0;
	
	for(int x=0; x<2; x++)
	{
		// ensure that x does not become greater than N
		if(lo1 == 0 && x > A[indx])
			break;
		
		for(int y=0; y<2; y++)
		{
			// ensure that y does not become greater than x
			if(lo2 == 0 && y > x)
				break;
			
			// are the carry flags in accordance with what we want
			if((x + y + carry2 > 1) == carry1 && (x ^ y ^ ((x + y + carry2) % 2)) == B[indx])
			{
				// the next bit may or may not have a carry, try both possibilities
				ans += solve(indx+1, (lo1 | (x < A[indx])), (lo2 | (y < x)), carry2, 0, (is_zero | (y > 0)));
				ans += solve(indx+1, (lo1 | (x < A[indx])), (lo2 | (y < x)), carry2, 1, (is_zero | (y > 0)));
			}
		}
	}
	
	return dp[indx][lo1][lo2][carry1][carry2][is_zero] = ans % MOD;
}
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	
	int T;
	cin >> T;
	
	while(T--)
	{
		long long N;
		cin >> N;
		
		long long target = 0;
		
		if(N % 4 == 0)
			target = N;
		else if(N % 4 == 1)
			target = 1;
		else if(N % 4 == 2)
			target = N + 1;
		
		getNum(N, A);
		getNum(target, B);
		
		while(B.size() < A.size())
			B.push_back(0);
		
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		
		memset(dp, -1, sizeof(dp));
		
		// lo1 = 0 : x is not lower than N yet
		// lo2 = 0 : y is not lower than x yet
		// carry1 = 0 : we are not allowed to generate a carry at the MSB
		// carry2 = {0, 1} : the next position may or may not have a carry
		// is_zero = 0 : we will set it to 1 if atleast 1 non-zero bit is used
		
		cout << (solve(0, 0, 0, 0, 0, 0) + solve(0, 0, 0, 0, 1, 0)) % MOD << "\n";
	}
	
	return 0;
}