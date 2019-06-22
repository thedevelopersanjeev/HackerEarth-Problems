class Solution {
public:
    int mySqrt(int A) {
    
    if(A < 0)
        return -1;
        
    if(A == 0 || A == 1)
        return A;
    
    int lo = 1, hi = A;
    
    int mid = lo + (hi - lo) / 2;
    
    while(mid > A / mid || (mid + 1) <= A / (mid + 1)){
        
        if(mid > A / mid)
            hi = mid;
            
        else
            lo = mid;
            
        mid = lo + (hi - lo) / 2;
        
    }
    
    return mid;
    
        
    }
};