#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, k;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    vector<int> digits(n);
    for (int i = 0; i < n; i++)
      digits[i] = s[i] - '0';
    int ans = INT_MIN;
    int i = 0;
    while (i <= n - k) {
      int count = 1, temp = 1;
      for (int j = i; count <= k; j++, count++)
        temp *= digits[j];
      ans = max(ans, temp);
      i++;
    }
    cout << ans << "\n";
  }
  return 0;
}