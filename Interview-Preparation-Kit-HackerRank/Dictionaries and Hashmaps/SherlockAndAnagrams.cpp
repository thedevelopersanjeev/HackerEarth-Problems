#include<bits/stdc++.h>
using namespace std;

template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs) {
    return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >>n;
	string s;
	while(n--){
		cin >>s;
		int size = s.size();
		vector<string> allsubs;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size - i; j++){
				allsubs.push_back(s.substr(i, j+1));
			}
		}
		int ans = 0;
		for(int i = 0; i < allsubs.size() - 1; i++){
			for(int j = i+1; j < allsubs.size(); j++){
				if(allsubs[i].size() == allsubs[j].size()){
					map<char, int> freqA, freqB;
					for(auto x : allsubs[i])
						freqA[x]++;
					for(auto x : allsubs[j])
						freqB[x]++;
					if(map_compare(freqA, freqB) == 1)
						ans++;
				}
			}
		}
		cout <<ans <<endl;
	}

}