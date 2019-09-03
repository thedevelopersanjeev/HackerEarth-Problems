#include<bits/stdc++.h>

int Solution::solve(vector<string> &arr){

    double a = stod(arr[0]);
    double b = stod(arr[1]);
    double c = stod(arr[2]);
    int n = arr.size();
    for(int i = 3; i < n; i++){
        // check for (1, 2)
        if((a + b + c) > 1.0 && (a + b + c) < 2.0)
            return 1;
        // if greater than 2, replace max(a, b, c) by next double
        else if((a + b + c) >= 2.0){
            if(a > b && a > c)
                a = stod(arr[i]);
            else if(b > a && b > c)
                b = stod(arr[i]);
            else if(c > a && c > b)
                c = stod(arr[i]);
        }
        // if less than 1, replace min(a, b, c) by next double
        else if((a + b + c) <= 1.0){
            if(a < b && a < c)
                a = stod(arr[i]);
            else if(b < a && b < c)
                b = stod(arr[i]);
            else if(c < a && c < b)
                c = stod(arr[i]);
        }
    }
    // check for last a, b, c
    return (a + b + c) > 1.0 && (a + b + c) < 2.0;

}
