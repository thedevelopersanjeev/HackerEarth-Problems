int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    vector<long long> pre(n, 0);
    pre[0] = arr[0];
    for(int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i-1];
    map<long long, long long> mp;
    for(auto ele : pre){
        if(mp[ele] != 0 || ele == 0)
            return 1;
        mp[ele]++;
    }
    return 0;
}
