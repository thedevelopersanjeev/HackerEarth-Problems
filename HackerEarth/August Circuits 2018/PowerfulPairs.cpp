#include"bits/stdc++.h"
#define LL long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
int sq;
const int N = 200005;
int A[N+2],L[N+2],R[N+2];
int vis[N+2];
int AA[N+2];
vector <int> adj[N+2];
int cnt = 0;
int ans = 0;
void dfs(int u){
    vis[u] = 1;
    L[u] = ++cnt;
    for(int i=0;i<adj[u].size();i++){
            int x = adj[u][i];
            if(!vis[x]){
                dfs(x);
            }
    }
    R[u] = cnt;
}
int cn[30*N+5];
int anss[N+2];
int lg = 20;
void add(int x)
{       
        x = A[x];
        cn[x]++;
        for(int i=0;i<=lg;i++){
            if((x&(1<<i))){
                int ser = (x^(1<<i));
                ans += cn[ser];
            }
            else{
                int ser = (x|(1<<i));
                ans += cn[ser];
            }
        }
}
void rmv(int x)
{       
        x = A[x];
        cn[x]--;
        for(int i=0;i<=lg;i++){
            if((x&(1<<i))){
                int ser = (x^(1<<i));
                ans -= cn[ser];
            }
            else{
                int ser = (x|(1<<i));
                ans -= cn[ser];
            }
        }
}
struct data{
    int l,r,ind,type;
    data(int a,int b,int c,int d){
        l = a; r = b; ind = c; type = d;
    }
    bool friend operator <(data A,data B) {
        int ba=(A.l/sq),bb=(B.l/sq);
        if(ba==bb) return A.r<B.r;
        else return ba<bb;
    }
};
vector <data> v;
signed main()
{
            int n;
            cin >> n;
            sq=sqrt(n+1);
            int a = 1;
            for(int i=1;i<=n;i++){
                cin >> AA[i];
            }
            int u,vv;
            for(int i=1;i<=n-1;i++){
                cin >> u >> vv;
                adj[u].pb(vv);
                adj[vv].pb(u);
            }
            dfs(1);
            for(int i=1;i<=n;i++){
                A[L[i]] = AA[i];
            }
            int q;
            cin >> q;
            for(int i=1;i<=q;i++){
                    cin >> u >> vv;
                    int a = L[u],b = R[u],c = L[vv],d = R[vv];
                    v.pb( data(a,d,i,+1) );
                    v.pb( data(a,c-1,i,-1) );
                    v.pb( data(b+1,d,i,-1) );
                    v.pb( data(b+1,c-1,i,+1) );
            }
            sort(v.begin(),v.end());
            int cl=v[0].l,cr=cl-1;
            ans = 0;
            for(int i=0; i<v.size(); i++) {
                        int l = v[i].l;
                        int r = v[i].r;
                        int ind = v[i].ind;
                        int ty = v[i].type;
                        while(cl<l) {
                            rmv(cl++);
                        }
                        while(cl>l) {
                            add(--cl);
                        }
                        while(cr<r) {
                            add(++cr);
                        }
                        while(cr>r) {
                            rmv(cr--);
                        }
                        anss[ind] += ty * ans;
                        
            }
            for(int i=1;i<=q;i++){
                cout << anss[i] << endl;
            }
            return 0;
}
 