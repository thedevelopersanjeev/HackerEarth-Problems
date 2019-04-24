class Solution {
public:
    int cache[31] = {0};
    int fib(int N) {
        if(cache[N] != 0)
            return cache[N];
        else if(N == 0 || N == 1){
            cache[N] = N;
            return cache[N];
        }
        else{
            cache[N] = fib(N-1) + fib(N-2);
            return cache[N];
        }
    }
};