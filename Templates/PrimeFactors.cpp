#include <bits/stdc++.h>
using namespace std;

// generated using sieve
vector<int> primeNumbers;

// find prime factors of n
vector<int> primeFactors(int n) {
    vector<int> ans;
    int idx = 0, p = primeNumbers[idx];
    while (p * p <= n) {
        while (n % p == 0) {
            n /= p;
            ans.push_back(p);
        }
        p = primeNumbers[++idx];
    }
    if (n != 1) {
        ans.push_back(n);
    }
    return ans;
}

// find number of factors/divisors of n
int numberOfFactors(int n) {
    int idx = 0, p = primeNumbers[idx], ans = 1;
    while (p * p <= n) {
        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        ans *= (e + 1);
        p = primeNumbers[++idx];
    }
    if (n != 1) {
        ans *= 2;
    }
    return ans;
}

// find sum of factors of n
int sumOfFactors(int n) {
    int idx = 0, p = primeNumbers[idx], ans = 1;
    while (p * p <= n) {
        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        ans *= (pow(p, e + 1) - 1) / (p - 1);
        p = primeNumbers[++idx];
    }
    if (n != 1) {
        ans *= (pow(n, 2) - 1) / (n - 1);
    }
    return ans;
}

// number of integers in [1, n - 1] such that it is co prime with n
int eulerPhi(int n) {
    int idx = 0, p = primeNumbers[idx], ans = n;
    while (p * p <= n) {
        if (n % p == 0) {
            ans -= ans / p;
        }
        while (n % p == 0) {
            n /= p;
        }
        p = primeNumbers[++idx];
    }
    if (n != 1) {
        ans -= ans / n;
    }
    return ans;
}
