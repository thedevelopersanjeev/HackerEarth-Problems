#include <bits/stdc++.h>
using namespace std;
long long ans, pairs, left_indices, right_indices;
int A[100005];
int rep[1000006], freq[1000006], group_size[1000006];
long long F[100005];
long long indices_self[1000006], indices_group[1000006];
vector< pair< pair<int, int>, pair<int, int> > > queries;
void add(int index, int other_end)
{
	int x = A[index];
	int p = rep[x];
	
	if(other_end < index)
	{
		ans += left_indices - 1LL * (other_end - 1) * pairs;
		ans += indices_group[p] - 1LL * (other_end - 1) * group_size[p];
		ans -= indices_self[x] - 1LL * (other_end - 1) * freq[x];
		
		pairs += group_size[p] - freq[x];
		left_indices += indices_group[p] - indices_self[x];
		right_indices += 1LL * index * (group_size[p] - freq[x]);
	}
	else if(other_end > index)
	{
		ans += 1LL * (other_end + 1) * pairs - right_indices;
		ans += 1LL * (other_end + 1) * group_size[p] - indices_group[p];
		ans -= 1LL * (other_end + 1) * freq[x] - indices_self[x];
		
		pairs += group_size[p] - freq[x];
		left_indices += 1LL * index * (group_size[p] - freq[x]);
		right_indices += indices_group[p] - indices_self[x];
	}
	
	group_size[p]++, freq[x]++;
	indices_group[p] += index, indices_self[x] += index;
}
void remove(int index, int other_end)
{
	int x = A[index];
	int p = rep[x];
	
	group_size[p]--, freq[x]--;
	indices_group[p] -= index, indices_self[x] -= index;
	
	if(other_end < index)
	{
		pairs -= group_size[p] - freq[x];
		left_indices -= indices_group[p] - indices_self[x];
		right_indices -= 1LL * index * (group_size[p] - freq[x]);
		
		ans -= left_indices - 1LL * (other_end - 1) * pairs;
		ans -= indices_group[p] - 1LL * (other_end - 1) * group_size[p];
		ans += indices_self[x] - 1LL * (other_end - 1) * freq[x];
	}
	else if(other_end > index)
	{
		pairs -= group_size[p] - freq[x];
		left_indices -= 1LL * index * (group_size[p] - freq[x]);
		right_indices -= indices_group[p] - indices_self[x];
		
		ans -= 1LL * (other_end + 1) * pairs - right_indices;
		ans -= 1LL * (other_end + 1) * group_size[p] - indices_group[p];
		ans += 1LL * (other_end + 1) * freq[x] - indices_self[x];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
	
	for(int i=1; i<=1000000; i++)
		rep[i] = i;
	
	for(int i=2; i<=1000000; i++)
		if(rep[i] == i)
		{
			for(int j=i; j<=1000000; j += i)
			{
				while(rep[j]/i % i == 0)
					rep[j] /= i;
			}
		}
	
	int N, Q;
	cin >> N >> Q;
	
	for(int i=1; i<=N; i++)
		cin >> A[i];
	
	int block = sqrt(N);
	
	for(int i=1; i<=Q; i++)
	{
		int L, R;
		cin >> L >> R;
		
		queries.push_back({{(L-1)/block+1, R}, {L, i}});
	}
	
	sort(queries.begin(), queries.end());
	
	add(1, 1);
	int left = 1, right = 1;
	
	for(auto &it : queries)
	{
		int L = it.second.first;
		int R = it.first.second;
		int index = it.second.second;
		
		while(left > L)
			add(--left, right);
		while(right < R)
			add(++right, left);
		while(left < L)
			remove(left++, right);
		while(right > R)
			remove(right--, left);
		
		F[index] = ans;
	}
	
	for(int i=1; i<=Q; i++)
		cout << F[i] << "\n";
	
	return 0;
}