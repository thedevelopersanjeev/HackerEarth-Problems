class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        
        int t = arr[0];
        int h = arr[0];
        do{
            t = arr[t];
            h = arr[arr[h]];
        }while(h != t);
        
        int p1 = arr[0];
        int p2 = t;
        while(p1 != p2){
            p1 = arr[p1];
            p2 = arr[p2];
        }
        return p1;
            
    }
};