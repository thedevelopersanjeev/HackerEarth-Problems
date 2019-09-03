#include<bits/stdc++.h>

int Solution::isPrime(int n){
    
    // base cases
    if(n <= 1)
        return false;

    if(n <= 3)
        return true;

    // even numbers and number divisible by 3
    if(n%2 == 0 || n%3 == 0)
        return false;

    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i+2) == 0)
            return false;
    }

    return true;

}
