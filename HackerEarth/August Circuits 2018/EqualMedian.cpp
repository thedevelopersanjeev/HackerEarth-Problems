#include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair <int, int> pii;
    typedef pair <ll, ll> pll;
    typedef pair <ll, int> pli;
    typedef pair <int, ll> pil;
     
    template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
     
    template<typename Args>
    void kill(Args args)
    {
        cout << args << "\n";
        exit(0);
    }
     
    #define add(x) emplace_back(x)
    #define pb(x) push_back(x)
    #define endl "\n"
    #define all(x) (x).begin(), (x).end()
    #define sz(x) (int)x.size()
    #define fill(a, v) memset(a, v, sizeof a)
    #define mp make_pair
    #define debug1(x) cerr << "at line " << __LINE__ << ": " << #x << " = " << (x) << endl
    #define debug2(x) cerr << #x << " = " << (x) << endl
     
     
    const double PI = acos(-1);
    const ll MOD = 1000000007;
    const int INF = 0x3f3f3f3f;
    const ll LLINF = 0x3f3f3f3f3f3f3f3f;
     
    const int N=101010;
    int n;
    int a[N],b[N],tot[2*N];
     
    void solve(int testnum){
          cin>>n;  
          for(int i=1;i<=n;i++){
              cin>>a[i];
              tot[i]=a[i];
          }
          for(int i=1;i<=n;i++){
              cin>>b[i];
              tot[n+i]=b[i];
          }
          sort(tot+1,tot+n+n+1);
          if(tot[n]!=tot[n+1]){
              cout<<-1<<endl;
              return;
          }
          int med=tot[n];
          int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0;
          for(int i=1;i<=n;i++){
              if(a[i]<med){
                  a1++;
              }
              else if(a[i]==med){
                  b1++;
              }
              else c1++;
          }
          for(int i=1;i<=n;i++){
              if(b[i]<med){
                  a2++;
              }
              else if(b[i]==med){
                  b2++;
              }
              else c2++;
          }
          assert(a1+a2<=n-1);
          assert(c1+c2<=n-1);
          int maxx=max(a1,max(a2,max(c1,c2)));
          if(maxx<=n/2){
              assert(b1!=0 && b2!=0);
              cout<<0<<endl;
              return;
          }
          cout<<maxx-(n/2)<<endl;
     
    }
     
    void precompute(){
     
    }
     
    int main(){
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        cout<<fixed<<setprecision(12);
        int testcase=1;
        clock_t zzzx=clock();
        cin>>testcase;
        precompute();
        for(int i=1;i<=testcase;i++){
            solve(i);
        }
        double elapsed_time=(double)(clock()-zzzx)/CLOCKS_PER_SEC;
        debug2(elapsed_time);
        return 0;
    }
 
