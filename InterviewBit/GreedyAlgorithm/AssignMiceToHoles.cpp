int Solution::mice(vector<int> &mice, vector<int> &holes) {
    
    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());
    int n = mice.size();
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
        ans = max(ans, abs(mice[i]-holes[i]));
    return ans;
    
}
