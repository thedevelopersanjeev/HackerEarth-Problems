vector<int> Solution::solve(int p1, int p2, int p3, int k) {

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    map<int, int> mp;
    vector<int> ans;
    while(q.size() != 0){
        int x = q.top();
        q.pop();
        if(x != 1)
            ans.push_back(x);
        if(ans.size() >= k)
            break;
        if(mp[x*p1] == 0){
            mp[x*p1] = 1;
            q.push(x*p1);
        }
        if(mp[x*p2] == 0){
            mp[x*p2] = 1;
            q.push(x*p2);
        }
        if(mp[x*p3] == 0){
            mp[x*p3] = 1;
            q.push(x*p3);
        }
    }
    return ans;
    
}