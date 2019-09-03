#include<bits/stdc++.h>

int Solution::reverse(int num){

    bool flag = false;

    if(num < 0){
        num *= -1;
        flag = true;
    }

    if(num == 0)
        return 0;

    long long ans = 0;
            
    while(num != 0){
        ans = (ans * 10) + (num % 10);
        num /= 10;
    }

    if(flag)
        ans *= -1;
    
    if(ans > INT_MAX || ans < INT_MIN)
        return 0;
    
    return ans;

}
