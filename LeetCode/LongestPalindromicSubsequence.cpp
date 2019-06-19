class Solution {
public:
    int longestPalindromeSubseq(string A) {
        
        int n = A.size();
    
    int dp[n][n];
    
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            
            if(i == j)
                // string of length one is always a palindrome
                dp[i][j] = 1;
                
            else
                // initialisation
                dp[i][j] = 0;
            
        }
        
    }
    
    // fill upper half of table recursively
    for(int temp = 2; temp <= n; temp++){
        
        for(int i = 0; i < n - temp + 1; i++){
            
            int j = i + temp - 1;
            
            if (A[i] == A[j] && temp == 2)
                dp[i][j] = 2;
            
            else if (A[i] == A[j]) 
               dp[i][j] = dp[i+1][j-1] + 2; 
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]); 
            
        }
        
    }
    
    // longest palindromic subsequence from 0 to n - 1
    return dp[0][n-1];
        
    }
};