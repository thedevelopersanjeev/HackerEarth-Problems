#include<bits/stdc++.h>

// Print matrix elements in spiral order
// matrix dimensions : m x n
vector<int> Solution::spiralOrder(const vector<vector<int> > &matrix){

    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;
    int dir = 0, top = 0, left = 0, i;
    vector<int> result;
    // dir : direction of spiral
    while(top <= bottom && left <= right){
        // left to right
        if(dir == 0){
            for(i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;
        }
        // top to bottom
        else if(dir == 1){
            for(i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;
        }
        // right to left
        else if(dir == 2){
            for(i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }
        // bottom to top
        else{
            for(i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return result;

}
