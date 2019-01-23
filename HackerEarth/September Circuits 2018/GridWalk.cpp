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
using ll = long long;
 
const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
 
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
 
const int mod = 1000000007;
 
signed gen(int T){
    // mt19937 rng(43151);
    auto get_rand = [&](int64_t l, int64_t r){
        return uniform_int_distribution<int64_t>(l, r)(rng);
    };
    auto get_double = [&](double l, double r){
        return uniform_real_distribution<double>(l, r)(rng);
    };
    const int N = T;
    T = 1;
    ofstream o("gen.txt");
    o << T << "\n";
    for(int cas=0;cas<T;++cas){
        /// GEN HERE
        int n = get_rand(1, N), m = get_rand(1, N);
        o << n << ' ' << m << endl;
        FOR(i, 1, n) {
            int x = 1;
            FOR(j, 1, m) {
                x = get_rand(x, m);
                o << x << ' ';
            }
            o << endl;
        }
        vector<vector<int>> L(n - 1, vector<int>(m)), R = L;
        FOR(i, 0, n - 2) {
            FOR(j, 0, m - 1) {
                L[i][j] = get_rand(j == 0 ? 1 : L[i][j - 1], j == 0 or R[i][j - 1] == m ? m : R[i][j - 1] + 1);
                R[i][j] = get_rand(max(j == 0 ? 1 : R[i][j - 1], L[i][j]), m);
                o << L[i][j] << ' ';
            }
            o << endl;
        }
        FOR(i, 0, n - 2) {
            for (int x: R[i]) {
                o << x << ' ';
            }
            o << endl;
        }
        o << "\n";
    }
    o << endl;
    o.close();
    return 0;
}
 
void read(vector<vector<int>> &vec, bool dec) {
	for (auto &row: vec) {
		for (int &x: row) {
			cin >> x;
			x -= dec;
		}
	}
}
 
signed main()
{
    #ifdef LOCAL_RUN
    // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; 
	if(TTT < 0) return gen(-TTT);
	while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN
 
    ///CODE
	int n, m;
	cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m)), L(n - 1, vector<int>(m)), R(n - 1, vector<int>(m)), dp(n, vector<int>(m)), eq(n, vector<int>(m - 1));
	read(A, false), read(L, true), read(R, true);
	fill(dp[0].begin(), dp[0].end(), 1);
    FOR(i, 0, m - 2) {
        eq[0][i] = A[0][i] == A[0][i + 1];
    }
    FOR(i, 0, n - 2) {
        FOR(j, 0, m - 1) {
            int l = L[i][j], r = R[i][j];
            dp[i + 1][l] += dp[i][j];
            NORM(dp[i + 1][l]);
            if (l < m - 1) {
                eq[i + 1][l] += dp[i][j];
                NORM(eq[i + 1][l]);
            }
            if (r + 1 < m) {
                dp[i + 1][r + 1] += mod - dp[i][j];
                NORM(dp[i + 1][r + 1]);
                eq[i + 1][r] += mod - dp[i][j];
                NORM(eq[i + 1][r]);
            }
            if (j < m - 1) {
                l = L[i][j + 1];
                dp[i + 1][l] += mod - eq[i][j];
                NORM(dp[i + 1][l]);
                if (r + 1 < m) {
                    dp[i + 1][r + 1] += eq[i][j];
                    NORM(dp[i + 1][r + 1]);
                }
                if (l <= r) {
                    if (l < m - 1) {
                        eq[i + 1][l] += mod - eq[i][j];
                        NORM(eq[i + 1][l]);
                    }
                    if (r < m - 1) {
                        eq[i + 1][r] += eq[i][j];
                        NORM(eq[i + 1][r]);
                    }
                } else {
                    eq[i + 1][r] += eq[i][j];
                    NORM(eq[i + 1][r]);
                    if (l < m - 1) {
                        eq[i + 1][l] += mod - eq[i][j];
                        NORM(eq[i + 1][l]);
                    }
                }
            }
        }
        FOR(j, 1, m - 1) {
            dp[i + 1][j] += dp[i + 1][j - 1];
            NORM(dp[i + 1][j]);
            if (j < m - 1) {
                eq[i + 1][j] += eq[i + 1][j - 1];
                NORM(eq[i + 1][j]);
            }
        }
        FOR(j, 0, m - 2) {
            if (A[i + 1][j] != A[i + 1][j + 1]) {
                eq[i + 1][j] = 0;
            }
        }
    }
    int res = 0;
    FOR(i, 0, m - 1) {
        res += dp[n - 1][i];
        NORM(res);
        if (i < m - 1) {
            res += mod - eq[n - 1][i];
            NORM(res);
        }
    }
	cout << res << endl;
	
    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}