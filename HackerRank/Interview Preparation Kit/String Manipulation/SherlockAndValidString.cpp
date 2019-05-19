#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >>s;
	map<char, int> freq;
	for(int i = 0; i < s.size(); i++)
		freq[s[i]]++;
	vector<int> freqs;
	for(auto x : freq)
		freqs.push_back(x.second);
	sort(freqs.begin(), freqs.end());
	int max = freqs[0];
	int min = freqs[freq.size()-1];
	if(max == min || (max - min == 1 && count(freqs.begin(), freqs.end(), max) == 1) || (min == 1 && count(freqs.begin(), freqs.end(), min) == 1))
		cout <<"YES";
	else
		cout <<"NO";
	return 0;
}