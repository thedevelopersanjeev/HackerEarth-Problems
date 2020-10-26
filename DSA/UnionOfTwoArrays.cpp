#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(max(A, B))
// Space Complexity : O(max(A, B))
int solve(vector<int> &A, vector<int> &B, int N, int M) {
    vector<int> freq(100000, 0);
    for (const auto &ele : A)
        freq[ele]++;
    for (const auto &ele : B)
        freq[ele]++;
    int ans = 0;
    for (const auto &ele : freq) {
        if (ele > 0) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (auto &ele : a) {
            cin >> ele;
        }
        for (auto &ele : b) {
            cin >> ele;
        }
        int ans = solve(a, b, n, m);
        cout << ans << "\n";
    }
    return 0;
}