#include<bits/stdc++.h>

int Solution::isPower(int num){

    if(num == 1)
        return 1;

    for(long long i = 2; i * i <= num; i++){
        long double val = log(num) / log(i);
        if((val - (int)val) < 0.00000001)
            return 1;
    }

    return 0;

}
