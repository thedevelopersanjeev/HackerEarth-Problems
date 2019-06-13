map<int, int> cache;
int Solution::climbStairs(int n) {
    if(cache[n] != 0)
        return cache[n];
    if(n <= 2)
        cache[n] = n;
    else
        cache[n] = climbStairs(n-1) + climbStairs(n-2);
    return cache[n];
}