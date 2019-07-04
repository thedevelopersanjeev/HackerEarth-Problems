vector<vector<int> >r;
vector<int>v;
bool memo[15];
map<vector<int>,bool>mapita;
void solve(int i,vector<int>uso){
    if(i==v.size()&&!mapita[uso]){
        mapita[uso]=true;
        r.push_back(uso);
        return;
    }
    for(int j=0;j<v.size();j++){
        if(!memo[j]){
            memo[j]=true;
            uso.push_back(v[j]);
            solve(i+1,uso);
            uso.pop_back();
            memo[j]=false;
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    v=A;
    r.clear();
    mapita.clear();
    vector<int>uso;
    solve(0,uso);
    return r;
}