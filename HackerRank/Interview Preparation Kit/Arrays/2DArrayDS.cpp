#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int maximum_sum = INT_MIN;
    for(int i=0; i<=3; i++){
        for(int j=0; j<=3; j++){
            if(maximum_sum < (arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]))
                maximum_sum = (arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]);
        }
        
        
        
    }
    return maximum_sum;
}

int main()
{
    vector<vector<int>> arr;
    int ele;
    for(int i=0; i<6; i++){
        vector<int> temp;
        for(int j=0; j<6; j++){
            cin >>ele;
            temp.push_back(ele);
        }
        arr.push_back(temp);
    }
    //cout <<hourglassSum(arr);
    cout <<hourglassSum(arr);
    return 0;
}
