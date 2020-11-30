#include <bits/stdc++.h>
using namespace std;

class BIT {
   private:
    vector<int> bit;
    vector<int> arr;
    int n;

   public:
    BIT(vector<int> &A) {
        arr = A;
        n = arr.size();
        bit.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            addElement(i, arr[i]);
        }
    }

    void addElement(int i, int ele) {
        i++;
        while (i <= n) {
            bit[i] += ele;
            i += (i & -i);
        }
    }

    void updateElement(int i, int ele) {
        int diff = ele - arr[i];
        arr[i] = ele;
        addElement(i, diff);
    }

    int getSum(int i) {
        i++;
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }

    int getSum(int i, int j) {
        return getSum(j) - getSum(i - 1);
    }
};