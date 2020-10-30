#include <bits/stdc++.h>
using namespace std;

// using prefix sum and checking every subarray
// time complexity => O(n ^ 2)
// space complexity=> O(n)
int maximumSumSubarray(vector<int> &arr) {
    vector<int> pre = arr;
    int n = arr.size(), ans = INT_MIN;
    partial_sum(arr.begin(), arr.end(), pre.begin());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int curr = pre[j];
            if (i != 0) {
                curr -= pre[i - 1];
            }
            ans = max(ans, curr);
        }
    }
    return ans;
}

// Kadane's Algorithm
// Time Complexity => O(n)
// Space Complexity=> O(1)
int kadaneAlgorithm(vector<int> &arr) {
    int ans = arr[0], curr = arr[0], n = arr.size();
    for (int i = 1; i < n; i++) {
        curr = max(curr + arr[i], arr[i]);
        ans = max(ans, curr);
    }
    return ans;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << kadaneAlgorithm(A) << "\n";
    }
    return 0;
}