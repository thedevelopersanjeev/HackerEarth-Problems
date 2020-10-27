#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(1)
void solve(vector<int> &arr, int n) {
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (auto &ele : arr) {
            cin >> ele;
        }
        solve(arr, n);
        for (const auto &ele : arr) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}