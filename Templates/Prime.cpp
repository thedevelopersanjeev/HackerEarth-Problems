#include <vector>
using namespace std;

// checks if a number is prime or not
// time complexity => O(sqrt(n))
bool isPrimeNumber(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// finds the prime factors of a number
// 24 ==> [2, 2, 2, 3]
vector<int> findPrimeFactors(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        ans.push_back(n);
    }
    return ans;
}
