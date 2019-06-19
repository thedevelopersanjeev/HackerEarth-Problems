class Solution {
public:
    int singleNumber(vector<int>& A) {
        int ans = 0;
    int mask = 0;
    int count = 0;
    // for 0 to 31st bit
    for(int i = 31; i >= 0; i--){
        count = 0;
        // set ith bit to one
        mask = (1<<i);
        for(auto ele : A)
            // ith bit is set in ele
            if(ele & mask)
                count++;
        if(count % 3 != 0)
            ans |= (1<<i);
    }
    return ans;
    }
};