#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cost_remove, cost_decrement;
	scanf("%d%d%d", &n, &cost_remove, &cost_decrement);
	map<int, int> cnt;
	vector<int> order;
	int answer = 0;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
		order.push_back(x);
	}
	sort(order.begin(), order.end());
	for(int x : order) {
		assert(cnt[x] >= 1);
		if(cnt[x] == 1) {
			continue;
		}
		--cnt[x];
		int shift = 0;
		while(cnt[x-shift]) {
			++shift;
		}
		if(cost_decrement * shift < cost_remove) {
			++cnt[x-shift];
			answer += cost_decrement * shift;
		}
		else {
			answer += cost_remove;
		}
	}
	printf("%d\n", answer);
	return 0;
}