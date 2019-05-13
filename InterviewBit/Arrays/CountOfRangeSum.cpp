int Solution::solve(vector<int> &nums, int lower, int upper) {

    multiset<long long> pSum;
        int res = 0,  i; 
        long long left, right, sum=0;
        for(i=0,pSum.insert(0); i<nums.size(); ++i){
            sum +=nums[i];
            res += std::distance(pSum.lower_bound(sum-upper), pSum.upper_bound(sum-lower));
            pSum.insert(sum);
        }
    return res;
    
}
