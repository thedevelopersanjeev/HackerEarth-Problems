// An array contains both positive and negative numbers in random order.Rearrange the array elements so that all negative numbers appear before all positive numbers.
// Input => -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output=> -12 -6 -13 -5 -3 -7 5 6 11

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void inplaceMerge(vector<int> &arr, int start, int mid, int end) {
    int i = start, j = mid + 1;
    while (i <= mid && arr[i] < 0) {
        i++;
    }
    while (j <= end && arr[j] < 0) {
        j++;
    }
    reverseArray(arr, i, mid);
    reverseArray(arr, mid + 1, j - 1);
    reverseArray(arr, i, j - 1);
}

void solveUsingMergeSort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        solveUsingMergeSort(arr, start, mid);
        solveUsingMergeSort(arr, mid + 1, end);
        inplaceMerge(arr, start, mid, end);
    }
}

void solve(vector<int> &arr) {
    int i = 0, j = arr.size() - 1;
    while (i <= j) {
        if (arr[i] < 0 && arr[j] < 0) {
            i++;
        } else if (arr[i] > 0 && arr[j] < 0) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else if (arr[i] < 0 && arr[j] > 0) {
            i++;
            j--;
        } else if (arr[i] > 0 && arr[j] > 0) {
            j--;
        }
    }
}

int main() {
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    cout << "Input => ";
    for (const auto &ele : arr) {
        cout << ele << " ";
    }
    cout << "\n";
    solveUsingMergeSort(arr, 0, arr.size() - 1);
    cout << "Output => ";
    for (const auto &ele : arr) {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}