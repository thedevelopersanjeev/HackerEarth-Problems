bool solve(vector<vector<string>> &board, string word) {
	int n = board.size(), m = board[0].size(), len = word.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string curr = "";
			for (int k = j; k < min(j + len, m); k++) {
				curr += board[i][k];
			}
			if (curr == word) {
				return true;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			string curr = "";
			for (int k = i; k < min(i + len, n); k++) {
				curr += board[k][j];
			}
			if (curr == word) {
				return true;
			}
		}
	}
	return false;
}