#include<bits/stdc++.h>

int Solution::trailingZeroes(int n){

    int cnt = 0;

    while(n > 1){
        
        cnt += (n / 5);
        
        n /= 5;
        
    }
    
    return cnt;

}
