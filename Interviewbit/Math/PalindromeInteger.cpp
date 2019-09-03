#include<bits/stdc++.h>

int Solution::isPalindrome(int num){

    if(num < 0)
        return 0;

    if(num == 0)
        return 1;

    int temp = 0, m = num;
    while(m != 0){
        temp = (temp * 10) + (m % 10);
        m /= 10;
    }

    return temp == num;

}
