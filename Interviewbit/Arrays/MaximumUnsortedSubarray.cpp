vector<int> Solution::subUnsort(vector<int> &A) {
	int n = A.size();
	int i = 0, j = n - 1;
	for(i = 0; i < n - 1; i++) {
		// found the starting point
		if(A[i] > A[i + 1])
			break;
	}
	if(i == n - 1) {
		// array is already sorted
		return vector<int>{-1};
	}
	for(int j = n - 1; j > 0; j--) {
		// found ending point
		if(A[j] < A[j - 1]) 
			break;
	}
	// find max and min in A[i...j]
	int mx = A[i], mn = A[i];
	for(int k = i + 1; k <= j; k++) {
		if(A[k] > mx)
			mx = A[k];
		if(A[k] < mn)
			mn = A[k];
	}
	for(int k = 0; k < i; k++) {
		if(A[k] > mn) {
			i = k;
			break;
		}
	}
	for(int k = n - 1; k >= e + 1; k--) {
		if(A[k] < mx) {
			j = k;
			break;
		}
	}
	return vector<int>{i, j};
}
