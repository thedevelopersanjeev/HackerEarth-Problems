#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int N;
    vector<int> arr;
    vector<int> bit;

    void init(vector<int> &A) {
        arr = A;
        int n = arr.size();
        N = n + 1;
        bit.resize(N);
        for (int i = 0; i < arr.size(); i++) {
            addElement(i, arr[i]);
        }
    }

    int prefixSum(int index) {
        int answer = 0;
        index++;
        while (index > 0) {
            answer += bit[index];
            index -= (index & -index);
        }
        return answer;
    }

    int rangeSum(int L, int R) {
        return prefixSum(R) - prefixSum(L - 1);
    }

    void addElement(int index, int delta) {
        index++;
        while (index < N) {
            bit[index] += delta;
            index += (index & -index);
        }
    }

    void updateElement(int index, int element) {
        int delta = element - arr[index];
        arr[index] = element;
        addElement(index, delta);
    }
};