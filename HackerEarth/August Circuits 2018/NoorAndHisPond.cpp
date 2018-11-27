#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++)
            cin >>v[i].second >>v[i].first;
        sort(v.begin(), v.end());
        multiset<int> m;
        auto ans = m.size();
        for(auto e : v){
            m.insert(e.second);
            while(m.size() && *m.begin() <= e.first)
                m.erase(m.begin());
            ans = max(ans, m.size());
        }
        cout <<ans <<"\n";
    }
    return 0;
}