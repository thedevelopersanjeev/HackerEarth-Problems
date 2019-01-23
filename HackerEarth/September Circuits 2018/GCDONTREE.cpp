#include <bits/stdc++.h>
 
#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(vlong i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((vlong)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;
#define MOD(x,y) (((x)*(y))%mod)
#define ODD(x) (((x)&1)==0?(0):(1))
 
using namespace std;
 
typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < vlong, vlong > pll;
typedef vector<pll> vll;
typedef vector<vlong> vl;
 
const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
using ll = long long;
 
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}
 
#ifdef DEBUG
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);
 
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif
 
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
 
//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
 
inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}
 
vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
 
inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}
 
inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}
 
inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}
 
/***********Template Ends Here***********/
 
signed gen(int T){
    mt19937 rng(43151);
    auto get_rand = [&](int64_t l, int64_t r){
        return uniform_int_distribution<int64_t>(l, r)(rng);
    };
    auto get_double = [&](double l, double r){
        return uniform_real_distribution<double>(l, r)(rng);
    };
    ofstream o("in.txt");
    o << T << "\n";
    for(int cas=0;cas<T;++cas){
        /// GEN HERE
 
        o << "\n";
    }
    o << endl;
    o.close();
    return 0;
}
 
const int N = 100000;
 
int sieve[N + 1], A[N + 1], total[N + 1], res[N];
vector<int> divisors[N + 1], graph[N];
map<int, int> counter[N];
 
void init() {
    iota(sieve, sieve + N + 1, 0);
    for (int i = 2; i * i <= N; i++) {
        if (sieve[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = i;
            }
        }
    }
    FOR(i, 1, N) {
        divisors[i].pb(1);
        int x = i;
        while (x > 1) {
            int p = sieve[x], c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            int n = SZ(divisors[i]);
            FOR(j, 1, c) {
                FOR(k, 1, n) {
                    divisors[i].pb(divisors[i].end()[-n] * p);
                }
            }
        }
    }
    timeStamp;
}
 
void dfs(int u, int p) {
    int big_size = 0, big_child = -1;
    for (int v: graph[u]) {
        if (v != p) {
            dfs(v, u);
            if (SZ(counter[v]) > big_size) {
                big_size = SZ(counter[v]);
                big_child = v;
            }
        }
    }
    if (big_child != -1) {
        counter[u] = move(counter[big_child]);
        for (int v: graph[u]) {
            if (v != p and v != big_child) {
                for (auto &it: counter[v]) {
                    int x = it.first, aux = counter[u][x] += it.second;
                    if (aux == total[x]) {
                        counter[u].erase(x);
                    }
                    xmax(res[u], x);
                }
            }
        }
    }
    for (int x: divisors[A[u]]) {
        total[x]--;
    }
    for (auto it = counter[u].end(); it != counter[u].begin(); ) {
        --it;
        if (it->second < total[it->first]) {
            xmax(res[u], it->first);
            break;
        }
    }
 
    for (int x: divisors[A[u]]) {
        int aux = ++counter[u][x];
        if (aux == ++total[x]) {
            counter[u].erase(x);
        }
    }
}
 
signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; 
	if(TTT < 0) return gen(-TTT);
	while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN
 
    ///CODE
    init();
    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        cin >> A[i];
        for (int x: divisors[A[i]]) {
            total[x]++;
        }
    }
    FOR(i, 0, n - 2) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(0, -1);
    FOR(i, 0, n - 1) {
        cout << res[i] << ' ';
    }
    cout << endl;
 
    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}