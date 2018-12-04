class Solution {
public:
    int climbStairs(int n) {
        return pow((1 + sqrt(5))*0.5, n+1)/sqrt(5)+0.5;
    }
};