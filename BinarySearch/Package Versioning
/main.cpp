vector<int> splitVersion(const string &version) {
	istringstream s(version);
	string temp;
	vector<int> ans;
	while (getline(s, temp, '.')) {
		ans.push_back(stoi(temp));
	}
	return ans;
}

bool solve(string older, string newer) {
	vector<int> olderVersion = splitVersion(older);
	vector<int> newerVersion = splitVersion(newer);
	if (olderVersion[0] > newerVersion[0]) {
		return false;
	} else if (olderVersion[0] < newerVersion[0]) {
		return true;
	}
	if (olderVersion[1] > newerVersion[1]) {
		return false;
	} else if (olderVersion[1] < newerVersion[1]) {
		return true;
	}
	if (olderVersion[2] >= newerVersion[2]) {
		return false;
	} else {
		return true;
	}
}