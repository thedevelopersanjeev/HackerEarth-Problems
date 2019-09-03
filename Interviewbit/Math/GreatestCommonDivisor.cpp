#include<bits/stdc++.h>

int findGCD(int x, int y){
    if(x == 0)
        return y;
    if(y == 0)
        return x;
    if(x == y)
        return x;
    return findGCD(max(x, y) - min(x, y), min(x, y));
}

int Solution::gcd(int x, int y){

    return findGCD(x, y);

}
