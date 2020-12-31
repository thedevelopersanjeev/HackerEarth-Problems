class Solution {
public:
    double average(vector<int>& salary) {
        int mx = *max_element(salary.begin(), salary.end());
        int mn = *min_element(salary.begin(), salary.end());
        int sm = accumulate(salary.begin(), salary.end(), 0);
        sm -= mx;
        sm -= mn;
        return (sm * 1.0) / (salary.size() - 2);
    }
};