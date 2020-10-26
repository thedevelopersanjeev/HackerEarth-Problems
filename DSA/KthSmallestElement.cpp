#include <bits/stdc++.h>
using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

int solve(vector<int> &arr, int k) {
    max_heap<int> heap;
    int n = arr.size();
    for (int i = 0; i < k; i++) {
        heap.push(arr[i]);
    }
    for (int i = k; i < n; i++) {
        if (arr[i] < heap.top()) {
            heap.pop();
            heap.push(arr[i]);
        }
    }
    return heap.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;
        cout << solve(arr, k) << "\n";
    }
    return 0;
}