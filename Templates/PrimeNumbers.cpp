#include <bits/stdc++.h>
using namespace std;

// checks if n is prime number or not
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}