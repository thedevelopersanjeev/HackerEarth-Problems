#include <cstdio>
 
#include <cstring>
 
#include <string>
#include <vector>
#include <algorithm>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
 
using namespace std;
 
#define SZ(a) int((a).size())
#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
 
typedef pair<int,int> II;
 
// Code adapted from ADJA
struct SuffixArray {
   static const int ALPHABET_SIZE = 256;
 
   vector<int> pos;
   vector< vector<int> > ranks;
   vector<int> lcp;
 
   // OUTPUT:
   // pos = Contains the N suffixes of str sorted in lexicographical order.
   //       Each suffix is represented as a single integer: the position where
   //       it starts in string str
   // ranks = The inverse of the suffix array.
   //         ranks[k][i] = the (one-based) index of the suffix str[i..n) in the
   //         pos array after the kth iteration. In particular, ranks[K][i] = j
   //         IFF pos[j-1] = i where K is ranks.size()-1.
   // lcp[i] = length of longest common prefix of suffix str[pos[i]..N)
   //          and suffix str[pos[i+1]..N)
 
 
   int N;
   SuffixArray(int _N, const char *str) : N(_N) {
      N++;  // assumes str is a NUL terminated char array
 
      int MAXLOG = 0;
      while ((1<<MAXLOG) < N)
         ++MAXLOG;
 
      pos = vector<int>(N);
      ranks = vector< vector<int> >(MAXLOG+1, vector<int>(N));
 
      vector<int> num( max(N, ALPHABET_SIZE) );
 
      for (int i = 0; i < N; ++i) 
         num[ str[i] ]++;   
 
      for (int t = 1; t < ALPHABET_SIZE; ++t)
         num[t] += num[t - 1];
 
      for (int i = 0; i < N; ++i) {
         int t = str[i];
         pos[ --num[t] ] = i;
      }
 
      int max_class_id;
      ranks[0][pos[0]] = max_class_id = 0;
      for (int i = 1; i < N; ++i) {
         if (str[ pos[i] ] != str[ pos[i - 1] ])
            max_class_id++;
         ranks[0][ pos[i] ] = max_class_id;
      }
 
      vector<int> pcur(N);
      for (int k = 1; ; ++k) {
         int half = (1 << (k - 1));    
         
         for (int i = 0; i < N; ++i) {
            pcur[i] = pos[i] - half;
            if (pcur[i] < 0) pcur[i] += N;
         }
 
         for (int t = 0; t <= max_class_id; ++t)
            num[t] = 0;
         for (int i = 0; i < N; ++i) 
            num[ ranks[k - 1][ pcur[i] ] ]++;
         for (int t = 1; t <= max_class_id; ++t)
            num[t] += num[t - 1];
           
         for (int i = N - 1; i >= 0; --i) {
            int t = ranks[k - 1][ pcur[i] ];
            pos[--num[t]] = pcur[i];
         }
 
         ranks[k][ pos[0] ] = max_class_id = 0;
         for (int i = 1; i < N; ++i) {
            int p1 = pos[i] + half, p2 = pos[i - 1] + half;
            if (p1 >= N) p1 -= N;   // circular string?
            if (p2 >= N) p2 -= N;
            if (ranks[k - 1][pos[i]] != ranks[k - 1][pos[i - 1]] ||
                ranks[k - 1][p1] != ranks[k - 1][p2])
               max_class_id++;
            ranks[k][ pos[i] ] = max_class_id;
         }
 
         if ((1 << k) >= N)
            break;
      }
 
      for (int i = 0; i < N-1; ++i)
         pos[i] = pos[i + 1];
      pos.pop_back();
      N--;
   }
 
};
 
 
int N, L;
int RQ[5][25004];
char STR[5*25004+10];
 
void solve() {
   int STR_SZ = 0;
   REP(n, N) {
      REP(j, L) {
         STR[STR_SZ++] = 'A' + RQ[n][j] - 1;
      }
      STR[STR_SZ++] = '0' + n;
   }
   STR[STR_SZ] = 0;
   
   SuffixArray sa(STR_SZ, STR);
 
   const int K = int(sa.ranks.size()) - 1;
/*   
   fprintf(stderr, "Suffix Array:\n");
   for (int i = 0; i < (int) sa.pos.size(); i++)
      fprintf(stderr, "%2d: pos=%2d  %s\n", i, sa.pos[i], STR+sa.pos[i]);
   fprintf(stderr, "\n");
 
   fprintf(stderr, "Ranks:\n");
   for (int i = 0; i < STR_SZ; ++i)
      fprintf(stderr, "%2d: %2d\n", i, sa.ranks[K][i]);
*/
 
   vector<II> Q;
   REP(n, N) {
      int p = n*(L+1);
      Q.push_back(II(sa.ranks[K][p], p));
   }
 
   REP(t, N*L) {
      auto it = min_element(Q.begin(), Q.end());
      int p = it->second;
      Q.erase(it);
 
      if (t > 0)
         putchar(' ');
      printf("%d", STR[p]-'A'+1);
      ++p;
 
      if (STR[p] >= 'A') {
         Q.push_back(II(sa.ranks[K][p], p));
      }
   }
   putchar('\n');
}
 
int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   FOR(tc, 1, TC) {
      scanf("%d %d", &N, &L);
      REP(n, N) {
         REP(j, L)
            scanf("%d", &RQ[n][j]);
      }
      solve();
   }
 
   return 0;
}