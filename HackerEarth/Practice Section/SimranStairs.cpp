#include<bits/stdc++.h>

using namespace std;

long func(long n)
{

	if (n == 1 || n == 0)

		return 1;

	else if(n == 2)

		return 2;

	else

		return func(n-1) + func(n-2) + func(n-3);

	}


int main()
{

	ios_base::sync_with_stdio(false);
    
	cin.tie(NULL);

	long n;

	cin >>n;

	cout <<func(n);

	return 0;

	}