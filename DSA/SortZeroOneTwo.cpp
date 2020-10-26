#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr) {
    int x = 0, y = 0, z = 0;
    for (const auto &ele : arr) {
        if (ele == 0) {
            x++;
        } else if (ele == 1) {
            y++;
        } else {
            z++;
        }
    }
    int i = 0;
    while (x--) {
        arr[i++] = 0;
    }
    while (y--) {
        arr[i++] = 1;
    }
    while (z--) {
        arr[i++] = 2;
    }
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
        solve(arr);
        for (const auto &ele : arr) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}