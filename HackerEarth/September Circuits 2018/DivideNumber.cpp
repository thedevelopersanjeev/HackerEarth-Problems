#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
using namespace std;
 
#define N  100005
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
	{
		ll int n;
		cin>>n;
		vector<int> v;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				v.pb(i);
				if(i!=n/i)
				v.pb(n/i);
			}
		}
		ll int arr[n+1];
		memset(arr,-1,sizeof(arr));
		for(auto i:v)
		{
			for(auto j:v)
			{
				if(i+j>=n) continue;
				ll int tmp=i;
				tmp*=j;
				arr[i+j]=max(arr[i+j],tmp);
			}
		}
		ll int ans=-1;
		for(int i=1;i<n;i++)
		{
			if(arr[i]==-1||arr[n-i]==-1) continue;
			ans=max(arr[i]*arr[n-i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}