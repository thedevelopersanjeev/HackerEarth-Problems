#include <bits/stdc++.h>
using namespace std;

// single occurence of common element
vector<int> solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    set<int> X(A.begin(), A.end()), Y(B.begin(), B.end());
    for (const auto &ele : X)
        if (Y.count(ele) > 0) ans.push_back(ele);
    return ans;
}

// min occurence of common element <==> approach one
vector<int> solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> X, Y;
    for (const auto &ele : A) {
        X[ele]++;
    }
    for (const auto &ele : B) {
        Y[ele]++;
    }
    vector<int> ans;
    for (const auto &ele : X) {
        int cnt = min(ele.second, Y[ele.first]);
        while (cnt--) {
            ans.push_back(ele.first);
        }
    }
    return ans;
}

// min occurence of common element <==> approach two
vector<int> solve(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    int i = 0, j = 0, n = A.size(), m = B.size();
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            ans.push_back(A[i]);
            i++;
            j++;
        } else if (A[i] > B[j]) {
            j++;
        } else if (A[i] < B[j]) {
            i++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (auto &ele : A) {
        cin >> ele;
    }
    for (auto &ele : B) {
        cin >> ele;
    }
    vector<int> ans = solve(A, B);
    for (auto &ele : ans) {
        cout << ele << " ";
    }
    return 0;
}