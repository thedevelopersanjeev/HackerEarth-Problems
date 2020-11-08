#include <bits/stdc++.h>
using namespace std;

#define int long long

// isPrime[i] = 1 ==> i is a prime number
// isPrime[i] = 0 ==> i is not a prime number
bitset<10000010> isPrime;
vector<int> primeNumbers;

void sieve(int _sieve_size) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= _sieve_size; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= _sieve_size; j += i) {
                isPrime[j] = 0;
            }
            primeNumbers.push_back(i);
        }
    }
}

bool isPrimeNumber(int n) {
    for (int i = 0; i < primeNumbers.size(); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    sieve(10000000);
    return 0;
}