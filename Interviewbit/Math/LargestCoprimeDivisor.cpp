#include<bits/stdc++.h>

int Solution::cpFact(int A, int B) {

    while(__gcd(A, B) != 1)
        A /= __gcd(A, B);

    return A;

}
