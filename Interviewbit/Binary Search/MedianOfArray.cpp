// m <= n is ensured here
double findMedian(const vector<int> &A, int m, const vector<int> &B, int n) {
	int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
	while(iMin <= iMax) {
		int i = iMin + (iMax - iMin) / 2;
		int j = halfLen - i;
		if(i < iMax && B[j-1] > A[i]) {
			iMin = i + 1;
		}
		else if(i > iMin && A[i-1] > B[j]) {
			iMax = i - 1;
		}
		else {
			int maxLeft = 0;
			if(i == 0) {
				maxLeft = B[j-1];
			}
			else if(j == 0) {
				maxLeft = A[i-1];
			}
			else {
				maxLeft = max(A[i-1], B[j-1]);
			}
			if((m + n) % 2 == 0) {
				return maxLeft;
			}
			int minRight = 0;
			if(i == m) {
				minRight = B[j];
			}
			else if(j == n) {
				minRight = A[i];
			}
			else {
				minRight = min(A[i], B[j]);
			}
			return (maxLeft + minRight) / 2.0;
		}
	}
	return 0.0;
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
	int m = A.size();
	int n = B.size();
	if(m == 0 && n == 0) {
	    return 0.0;
	}
	if(m == 0) {
		if(n == 1) {
			return B[0] * 1.0;
		}
	    else if(n % 2 == 0) {
	        return (B[n/2] * B[(n/2) - 1]) / 2.0;
	    }
	    else {
	        return B[n/2] * 1.0;
	    }
	}
	if(n == 0) {
		if(m == 1) {
			return A[0] * 1.0;
		}
	    else if(m % 2 == 0) {
	        return (A[m/2] * A[(m/2) - 1]) / 2.0;
	    }
	    else {
	        return A[m/2] * 1.0;
	    }
	}
	if(m > n) {
		return findMedian(B, n, A, m);
	}
	else {
		return findMedian(A, m, B, n);
	}

}
