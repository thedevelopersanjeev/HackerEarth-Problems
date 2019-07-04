void f(vector<int>& candidates, vector<vector<int>>& res, vector<int>& item, int idx, int sum, int target){
        if(sum == target)
            res.push_back(item);
        if(idx >= candidates.size() || sum > target)
            return;
        for(int i = idx; i < candidates.size(); i++){
            item.push_back(candidates[i]);
            f(candidates, res, item, i+1, sum+candidates[i], target);
            while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
                i++;
            item.pop_back();
        }
    }

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    sort(A.begin(), A.end());

    vector<int> x;
    vector<vector<int>> ans;

    f(A, ans, x, 0, 0, B);
    
    return ans;
    
}
