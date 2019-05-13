int m = A.size(), n = A[0].size(), lo = 0, hi = m*n-1, mi, row, col;
    while(lo <= hi){
        // mid point
        mi = lo + ((hi-lo) >> 1);
        // row pointer
        row = mi / n;
        // column pointer
        col = mi % n;
        // match found : )
        if(A[row][col] == B) return 1;
        // current element is greater
        // so move to left
        else if(A[row][col] > B) hi = mi - 1;
        // current element is less
        // so move to right
        else lo = mi + 1;
    }
    // match not found : (
    return 0;