string Solution::longestCommonPrefix(vector<string> &A) {
    int size = A.size();
    // base case
    if(size == 0)
        return "";
    string prefix = A[0];
    for(int i = 1; i < size; i++){
        int j = 0, n = A[i].size();
        // while prefix matches with current string
        while(j < n && A[i][j] == prefix[j])
            j++;
        // trim the matching prefix till now
        prefix = prefix.substr(0, j);
    }
    // common prefix not found
    if(prefix.size() == 0)
        return "";
    return prefix;
}
