vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret; 
    int n = A.size();
    for (int i = 0; i < n; i++) {
        ret.push_back(A[(i + B)%n]);
    }
    return ret; 
}
