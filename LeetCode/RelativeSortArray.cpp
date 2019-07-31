class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto ele : arr1)
            mp[ele]++;
        for(auto ele : arr2){
            
            int kitnibaarhai = mp[ele];
            while(kitnibaarhai--){
                
                ans.push_back(ele);
                
            }
            
        }
        
        sort(arr2.begin(), arr2.end());
        
        vector<int> temp;
        
        // check ki koi reh to ni gya
        for(auto ele : arr1)
            if(!binary_search(arr2.begin(), arr2.end(), ele))
                temp.push_back(ele);
        
        sort(temp.begin(), temp.end());
        
        for(auto ele : temp)
            ans.push_back(ele);
        
        return ans;
        
    }
};