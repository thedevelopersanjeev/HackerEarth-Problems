#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int canReach = 0;
    for (int i = 0; i <= canReach; i++) {
        if (i == nums.size() - 1) {
            return true;
        }
        canReach = max(canReach, i + nums[i]);
    }
    return false;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> arr(N);
        for (auto& ele : arr) cin >> ele;
        if (canJump(arr) == false) {
            cout << "-1\n";
            continue;
        }
        int ans = 0, curr = 0, destination = 0;
        for (int i = 0; i < N - 1; i++) {
            destination = max(destination, i + arr[i]);
            if (curr == i) {
                curr = destination;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}