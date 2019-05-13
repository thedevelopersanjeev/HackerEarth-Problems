int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<pair<int, int> > mp(n);
    for(int i = 0; i < n; i++){
        mp[i].first = A[i];
        mp[i].second = i;
    }
    sort(mp.begin(), mp.end());
    int ans = 0, c = 0, j;
    for(int i = 0; i < n; i++){
        if(mp[i].second==i)  
            continue; 
        else{
            swap(mp[i].first, mp[mp[i].second].first); 
            swap(mp[i].second, mp[mp[i].second].second);  
        }
        if(i != mp[i].second) 
            --i;
        ans++;
    }
    return ans;
}