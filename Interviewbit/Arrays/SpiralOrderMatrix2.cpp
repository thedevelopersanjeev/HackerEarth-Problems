#include<bits/stdc++.h>

vector<vector<int>> Solution::generateMatrix(int n) {

    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int dir = 0;
    int val = 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    while(left <= right && top <= bottom){
        if(dir == 0){
            for(int i = left; i <= right; i++){
                ans[top][i] = val;
                val++;
            }
            top++;
        }
        else if(dir == 1){
            for(int i = top; i <= bottom; i++){
                ans[i][right] = val;
                val++;
            }
            right--;
        }
        else if(dir == 2){
            for(int i = right; i >= left; i--){
                ans[bottom][i] = val;
                val++;
            }
            bottom--;
        }
        else{
            for(int i = bottom; i >= top; i--){
                ans[i][left] = val;
                val++;
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;

}
