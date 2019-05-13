bool isPalindrome(string A){
    string B = A;
    reverse(A.begin(), A.end());
    return A == B;
}

int findAns(string A){
    if(isPalindrome(A))
        return 0;
    // remove last character
    A = A.substr(0, A.size()-1);
    return 1 + findAns(A);
}

int Solution::solve(string A) {
    return findAns(A);
}
