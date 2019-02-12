#include <bits/stdc++.h>
using namespace std;
long long A[505];
vector< pair<int, pair<int, int> > > negative_add, positive_add, all_set;
void addQueries(vector< pair<int, pair<int, int> > > &X)
{
	for(auto it : X)
	{
		int x = it.first;
		int L = it.second.first, R = it.second.second;
		
		for(int i=L; i<=R; i++)
			A[i] += x;
	}
}
void setQueries(vector< pair<int, pair<int, int> > > &X)
{
	for(auto it : X)
	{
		int x = it.first;
		int L = it.second.first, R = it.second.second;
		
		for(int i=L; i<=R; i++)
			A[i] = x;
	}
}
int main()
{
	int N, Q;
	cin >> N >> Q;
	
	for(int i=1; i<=N; i++)
		cin >> A[i];
	
	while(Q--)
	{
		int type, L, R, x;
		cin >> type >> L >> R >> x;
		
		if(type == 1)
		{
			if(x < 0)
				negative_add.push_back({x, {L, R}});
			else
				positive_add.push_back({x, {L, R}});
		}
		else
			all_set.push_back({x, {L, R}});
	}
	
	sort(all_set.begin(), all_set.end());
	
	addQueries(negative_add);
	setQueries(all_set);
	addQueries(positive_add);
	
	for(int i=1; i<=N; i++)
		cout << A[i] << " ";
	cout << "\n";
	
	return 0;
}
