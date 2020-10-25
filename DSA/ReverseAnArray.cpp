#include <bits/stdc++.h>
using namespace std;

void reverseArrayRecursive(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArrayRecursive(arr, start + 1, end - 1);
}

void reverseArrayIterative(vector<int> &arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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
        reverseArrayIterative(arr, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}