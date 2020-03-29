int Solution::maximumGap(const vector<int> &A) {
	if(A.size() < 2)
		return 0;
	int mx = *max_element(A.begin(), A.end());
	int mn = *min_element(A.begin(), A.end());
	int range = mx - mn + 1;
	vector<int> pigeonHole(range, 0);
	for(auto ele : A) {
		pigeonHole[ele - mn]++;
	}
	int ans = INT_MIN;
    int prev = -1;
    for(int i = 0; i < range; i++) {
        if(pigeonHole[i] > 0) {
        	
        }
    }
	return ans;
}
