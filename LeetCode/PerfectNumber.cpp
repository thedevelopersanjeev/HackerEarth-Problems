class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int ans = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if(num % i == 0) {
                ans += i;
                if(i != (num / i)) {
                    ans += (num / i);
                }
            }
        }
        return ans == num;
    }
};