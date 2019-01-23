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
 
signed gen(int T){
    mt19937 rng(43151);
    auto get_rand = [&](int64_t l, int64_t r){
        return uniform_int_distribution<int64_t>(l, r)(rng);
    };
    auto get_double = [&](double l, double r){
        return uniform_real_distribution<double>(l, r)(rng);
    };
    ofstream o("gen.txt");
    o << T << "\n";
    for(int cas=0;cas<T;++cas){
        /// GEN HERE
 
        o << "\n";
    }
    o << endl;
    o.close();
    return 0;
}
 
namespace FIO{
    char buf[32*1042|1];
    int bc=0, be=0;
    char gc(){
        if(bc>=be){
            be = fread(buf, 1, sizeof(buf)-1, stdin);
            buf[be] = bc = 0;
        }
        return buf[bc++];
    }
    void readint(){}
    void readuint(){}
    template<typename T, typename ...S>
    void readuint(T &a, S& ...b){
        a=0;
        int x=gc();
        while(x<'0' || x>'9') x=gc();
        while(x>='0' && x<='9'){
            a = a*10+x-'0'; x=gc();
        }
        readuint(b...);
    }
	template<typename T, typename ...S>
    void readint(T &a, S& ...b){
        a=0;
        int x=gc(), s=1;;
        while(x!='-' && (x<'0' || x>'9')) x=gc();
		if(x=='-'){ s=-s; x=gc(); }
        while(x>='0' && x<='9'){
            a = a*10+x-'0'; x=gc();
        }
		if(s<0) a=-a;
        readint(b...);
    }
    void readchar ( char &x ) {
        register char c = gc();
        while (c < 33) c = gc();
        x = c;
    }
    void readstring(char *str){
        register char c = 0;
        register int i = 0;
        while (c < 33)
            c = gc();
        while (c != '\n') {
            str[i] = c;
            c = gc();
            i = i + 1;
        }
        str[i] = '\0';
    }
}
using FIO::readint;
using FIO::readuint;
using FIO::readchar;
using FIO::readstring;
 
template<typename DOUBLE>
struct Simplex_Steep {
  using VD = vector<DOUBLE>;
  using VVD = vector<VD>;
  using VI = vector<int>;
  const DOUBLE EPS = 1e-12;
  int m, n;
  VI B, N;
  VVD D;
 
  int iteration_cnt = 0;
 
  Simplex_Steep(const VVD &A, const VD &b, const VD &c) :
    m(b.size()), n(c.size()), B(m), N(n+1), D(m+2, VD(n+2)) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
    for (int i = 0; i < m; i++) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i]; }
    for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
    N[n] = -1; D[m+1][n] = 1;
  }
 
  void Pivot(int r, int s) {
    for (int i = 0; i < m+2; i++) if (i != r)
      for (int j = 0; j < n+2; j++) if (j != s)
        D[i][j] -= D[r][j] * D[i][s] / D[r][s];
    for (int j = 0; j < n+2; j++) if (j != s) D[r][j] /= D[r][s];
    for (int i = 0; i < m+2; i++) if (i != r) D[i][s] /= -D[r][s];
    D[r][s] = 1.0 / D[r][s];
    swap(B[r], N[s]);
  }
 
  bool Simplex(int phase) {
    int x = phase == 1 ? m+1 : m;
    while (true) {
      ++iteration_cnt;
      int s = -1;
      DOUBLE c_val = -1;
      for (int j = 0; j <= n; j++) {
        if (phase == 2 && N[j] == -1) continue;
        DOUBLE norm_sq = 0;
        for(int k=0; k<=m;++k){ norm_sq+= D[k][j]*D[k][j];}
        if(norm_sq < EPS) norm_sq = EPS; // stop division by 0
        DOUBLE c_val_j = D[x][j] / sqrtl(norm_sq);
        if (s == -1 || c_val_j < c_val  || (c_val == c_val_j && N[j] < N[s])){
            s = j; c_val = c_val_j;
        }
      }
      if (D[x][s] >= -EPS) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
        if (D[i][s] <= EPS) continue;
        if (r == -1 || D[i][n+1] / D[i][s] < D[r][n+1] / D[r][s] ||
            (D[i][n+1] / D[i][s] == D[r][n+1] / D[r][s] && B[i] < B[r])) r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }
  
  DOUBLE solve(VD &x) {
    int r = 0;
    for (int i = 1; i < m; i++) if (D[i][n+1] < D[r][n+1]) r = i;
    if (D[r][n+1] <= -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m+1][n+1] < -EPS) return -numeric_limits<long double>::infinity();
      for (int i = 0; i < m; i++) if (B[i] == -1) {
        int s = -1;
        for (int j = 0; j <= n; j++)
          if (s == -1 || D[i][j] < D[i][s] || (D[i][j] == D[i][s] && N[j] < N[s])) s = j;
        Pivot(i, s);
      }
    }
    if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
    x = VD(n);
    for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n+1];
    //cerr << "Steepest edge iterations: " << iteration_cnt << "\n";
    return D[m][n+1];
  }
};
 
using DOUBLE = __float128;
 
const vlong MAXI = 10000000000000000ll, INF = inf << 32;
const int ITER = 100;
 
bool solve(const vl &furthest, DOUBLE delta, vector<vector<DOUBLE>> &A, vector<DOUBLE> &B, vector<DOUBLE> &C, vector<DOUBLE> &X) {
    int dim = __lg(SZ(furthest));
    fill(B.begin(), B.end(), INF);
    FOR(mask, 0, (1 << dim) - 1) {
        FOR(l, 0, dim - 1) {
            A[mask][l] = (mask & (1 << l)) ? -1 : 1;
        }
        xmin(B[mask], furthest[mask]);
        int comp = ((1 << dim) - 1) ^ mask;
        xmin(B[comp], -(furthest[mask] - delta));
    }
    DOUBLE ret = Simplex_Steep<DOUBLE>(A, B, C).solve(X);
    bool res = ret > -INF;
    return res;
}
 
 
DOUBLE search(const vl &furthest, vector<vector<DOUBLE>> &A, vector<DOUBLE> &B, vector<DOUBLE> &C, vector<DOUBLE> &X) {
    DOUBLE left = 0, right = INF;
    FOR(i, 1, ITER) {
        DOUBLE mid = (left + right) / 2;
        if (solve(furthest, mid, A, B, C, X)) {
            debug("YES");
            right = mid;
        } else {
            debug("NO");
            left = mid;
        }
    }
    return (left + right) / 2;
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
    int n, k;
    readint(n, k);
    vl furthest(1 << k, -INF), coords(k);
    vector<vector<DOUBLE>> A(1 << k, vector<DOUBLE>(k));
    vector<DOUBLE> B(1 << k), C(k), X(k);
    FOR(i, 1, n) {
        vlong value = 0;
        for (vlong &x: coords) {
            readint(x);
            x += MAXI;
            value += x;
        }
        FOR(mask, 0, (1 << k) - 1) {
            xmax(furthest[mask], value);
            int l = 0;
            while (mask & (1 << l)) {
                value += 2 * coords[l];
                l++;
            }
            value -= 2 * coords[l];
        }
    }
    DOUBLE res = 0;
    solve(furthest, res, A, B, C, X);
    cout << fixed << setprecision(12);
    for (DOUBLE &x: X) {
        x -= MAXI;
        cout << (long double)x << ' ';
    }
    cout << endl;
 
    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}