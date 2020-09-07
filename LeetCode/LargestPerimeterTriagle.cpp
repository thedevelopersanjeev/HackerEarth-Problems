class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n < 3)
            return 0;
        for(int i = n - 1; i >= 2; i--)
            if(arr[i] < arr[i - 1] + arr[i - 2])
                return arr[i] + arr[i - 1] + arr[i - 2];
        return 0;
    }
};