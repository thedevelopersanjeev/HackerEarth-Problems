#include <bits/stdc++.h>
using namespace std;

int mn, mx;

pair<int, int> solve(vector<int> &arr, int start, int end) {
    if (end - start <= 1) {
        int x = arr[start];
        int y = arr[end];
        mn = min({mn, x, y});
        mx = max({mx, x, y});
        return make_pair(mn, mx);
    }
    int mid = start + (end - start) / 2;
    solve(arr, start, mid);
    solve(arr, mid + 1, end);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        mn = INT_MAX;
        mx = INT_MIN;
        pair<int, int> ans = solve(arr, 0, n - 1);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}