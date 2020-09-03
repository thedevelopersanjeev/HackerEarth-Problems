class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(A[i] == B[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};