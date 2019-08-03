// Find the subset of an array having minimum product
// Brute Force Solution -- Not going to implement it obviously
// Generate all subsets and return the minimum
// Time Complexity - O(2^n)
#include<bits/stdc++.h>
using namespace std;

/**
 * Returns minimum product of subset of given array of integers
 */
int solve(vector<int> &arr){
    // frequency of +ve numbers
    int positive = 0;
    // frequency of negative numbers
    int negative = 0;
    // number of zeros
    int zeros = 0;
    for(auto ele : arr){
        if(ele == 0)
            zeros++;
        else if(ele > 0)
            positive++;
        else
            negative++;
    }
    /**
     * Case 1 : if there is no zero in the array and number of negative
     * numbers is odd, then the answer will be product of whole array
     */
    if(zeros == 0 && negative%2 == 1){
        int ans = 1;
        for(auto ele : arr)
            ans *= ele;
        return ans;
    }
    /**
     * Case 2 : if there is no zeros in the array and number of negative 
     * numbers is even, then answer will be product of all excluding 
     * the greatest negative number
     * example : {-10, -5, -3, -1, 1, 3, 5}, we need to exclude -1
     * answer = (-10 * -5 * -3 * 1 * 3 * 5) = -2250
     */
    if(zeros == 0 && negative%2 == 0){
        // first find greatest negative number
        int minimum = INT_MIN;
        for(auto ele : arr){
            if(ele < 0 && ele > minimum)
                minimum = ele;
        }
        // find the product excluding this number and zeros
        int ans = 1;
        for(auto ele : arr){
            if(ele != minimum)
                ans *= ele;
        }
        return ans;
    }
    /**
     * Case 3 : If there is a zero and no negative element,
     * answer is 0
     */
    if(zeros > 0 && negative == 0)
        return 0;
    /**
     * Case 4 : If there is no zero and no negative number
     * then, answer will be the minimum element
     */
    if(zeros == 0 && negative == 0)
        return *min_element(arr.begin(), arr.end());
    /**
     * Case 5 : There are some zeros and number of negative numbers 
     * is odd, then answer will be product of all numbers
     * excluding zero
     */
    if(zeros > 0 && negative%2 == 1){
        int ans = 1;
        for(auto ele : arr){
            if(ele != 0)
                ans *= ele;
        }
        return ans;
    }
    /**
     * Case 6 : There are some zeros and number of negative numbers is
     * even, then the answer will be product of all numbers excluding 
     * zeros and greatest negative number
     */
    if(zeros > 0 && negative > 0 && negative%2 == 0){
        // first find greatest negative number
        int minimum = INT_MIN;
        for(auto ele : arr){
            if(ele < 0 && ele > minimum)
                minimum = ele;
        }
        // find the product excluding this number and zeros
        int ans = 1;
        for(auto ele : arr){
            if(ele != 0 && ele != minimum)
                ans *= ele;
        }
        return ans;
    }
    // unhandled cases
    // never reach here
    return INT_MIN;
}

int main(){
    vector<int> a = {-1, -1, -2, 4, 3};
    vector<int> b = {-4, 0};
    vector<int> c = {0, 0, 0};
    cout <<solve(a) <<"\n";
    cout <<solve(b) <<"\n";
    cout <<solve(c) <<"\n";
    return 0;
}