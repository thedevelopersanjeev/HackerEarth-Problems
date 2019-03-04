#include <bits/stdc++.h>
 
using namespace std;
 
string to_string(string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
vector<int64_t> s;
 
class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      s[y] += s[x];
      return true;
    }
    return false;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(2 * n);
  vector<int64_t> w(n, 0);
  s.assign(2 * n, 0);
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y, z;
      cin >> x >> y >> z;
      x--; y--;
      w[x] += z;
      w[y] += z;
      d.unite(x, y + n);
      d.unite(x + n, y);
      s[d.get(x)] += z;
      s[d.get(y)] += z;
    } else {
      int x, y;
      cin >> y >> x;
      x--; y--;
      if (d.get(x) != d.get(y)) {
        cout << 0 << '\n';
        continue;
      }
      long long num = w[y];
      long long den = s[d.get(x)];
      if (num == 0 && den == 0) {
        cout << (int) 1e9 << '\n';
        continue;
      }
      debug(num, den);
      __int128 inf = (__int128) 2e9;
      cout << (long long) (((__int128) num * inf + den) / (2 * den)) << '\n';
    }
  }
  return 0;
}