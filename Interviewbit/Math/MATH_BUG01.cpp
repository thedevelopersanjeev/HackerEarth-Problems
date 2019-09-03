// Return 1 if A is prime, else 0
int Solution::isPrime(int A) {
    if(A == 1)
        return 0;
    int upperLimit = (int)(sqrt(A));
    for (int i = 2; i <= upperLimit; i++) {
        if (i < A && A % i == 0) return 0;
    }
    return 1;
}
