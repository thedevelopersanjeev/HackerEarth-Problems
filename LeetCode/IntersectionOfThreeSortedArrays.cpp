class Solution {
   public:
    vector<int> arraysIntersection(vector<int>& A, vector<int>& B, vector<int>& C) {
        int x = A.size(), y = B.size(), z = C.size(), i = 0, j = 0, k = 0;
        vector<int> ans;
        while (i < x && j < y && k < z) {
            if (A[i] == B[j] && B[j] == C[k]) {
                ans.push_back(A[i]);
                i++;
                j++;
                k++;
            } else if (A[i] <= B[j] && A[i] <= C[k]) {
                i++;
            } else if (B[j] <= A[i] && B[j] <= C[k]) {
                j++;
            } else if (C[k] <= A[i] && C[k] <= B[j]) {
                k++;
            }
        }
        return ans;
    }
};