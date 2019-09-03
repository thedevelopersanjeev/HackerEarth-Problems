#include<bits/stdc++.h>

vector<int> Solution::maxset(vector<int> &arr) {

    long long maxSum = 0, currSum = 0;
    vector<int> maxArray, currArray;
    for(auto ele : arr){
        if(ele >= 0){
            currSum += ele;
            currArray.push_back(ele);
        }
        else{
            currSum = 0;
            currArray.clear();
        }
        if((maxSum < currSum) || ((maxSum == currSum) && (currArray.size() > maxArray.size()))){
            maxSum = currSum;
            maxArray = currArray;
        }
    }
    return maxArray;

}