class Solution {
public:
    int compareVersion(string A, string B) {
        __int128 i = 0, j = 0, sizeA = A.size(), sizeB = B.size();
    while(i < sizeA || j < sizeB){
        __int128 x = 0, y = 0;
        while(i < sizeA && A[i] != '.'){
            x = x * 10 + (A[i] - '0');
            i++;
        }
        while(j < sizeB && B[j] != '.'){
            y = y * 10 + (B[j] - '0');
            j++;
        }
        if(x > y)
            return 1;
        if(x < y)
            return -1;
        i++;
        j++;
    }
    return 0;

    }
};