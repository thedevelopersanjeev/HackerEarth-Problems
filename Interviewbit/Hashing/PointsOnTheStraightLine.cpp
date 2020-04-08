int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
	vector<vector<int>> points;
	for (int i = 0; i < X.size(); i++) {
		points.push_back({X[i], Y[i]});
	}

	if (points.size() <= 2) return points.size();
	int res = 2;
	for (int i = 1; i < points.size(); i++) {
		int x0 = points[i - 1][0];
		int y0 = points[i - 1][1];
		int x1 = points[i][0];
		int y1 = points[i][1];
		int cnt = 0;
		if (x0 == x1 && y0 == y1) {
			for (int j = 0; j < points.size(); j++) {
				if (points[j][0] == x1 && points[j][1] == y1)
					cnt++;
			}
		}
		else {
			for (int j = 0; j < points.size(); j++) {
				int x2 = points[j][0];
				int y2 = points[j][1];
				if ((long long)(y2 - y1) * (x1 - x0) == (long long)(x2 - x1) * (y1 - y0)) cnt++;
			}
		}
		res = max(res, cnt);
	}
	return res;
}
