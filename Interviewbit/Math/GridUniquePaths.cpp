#include<bits/stdc++.h>

int Solution::uniquePaths(int A, int B) {

    if(A == 1 || B == 1)
        return 1;
    else
        return uniquePaths(A - 1, B) + uniquePaths(A, B - 1);
    
}
