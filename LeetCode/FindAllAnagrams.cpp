class Solution {
public:
    
    bool comp(vector<int> &A, const vector<int> &B){
    for(int i = 0; i < 256; i++)
        if(A[i] != B[i])
            return false;
    return true;
}
    
    vector<int> findAnagrams(string A, string B) {
        
        int n = A.size();
    int m = B.size();
    
    vector<int> patternfreq(256, 0);
    vector<int> textfreq(256, 0);
    vector<int> ans;
    
    for(int i = 0; i < m; i++){
        patternfreq[B[i]]++;
        textfreq[A[i]]++;
    }
    
    for(int i = m; i < n; i++){
        if(comp(patternfreq, textfreq))
            ans.push_back(i-m);
        // add current character
        textfreq[A[i]]++;
        // remove first character
        textfreq[A[i-m]]--;
    }
    
    if(comp(patternfreq, textfreq))
        ans.push_back(n-m);
        
    return ans;
        
    }
};