class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1, n = A.size();
        while(true){
            while(i < n && A[i]%2 == 0)
                i += 2;
            while(j < n && A[j]%2 == 1)
                j += 2;
            if(i < n && j < n)
                swap(A[i], A[j]);
            else
                break;
        }
        return A;
    }
};