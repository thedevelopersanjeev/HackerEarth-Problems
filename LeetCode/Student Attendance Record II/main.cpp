class Solution {
  public:

	const int mod = 1e9 + 7;

	int checkRecord(int n) {
		// 'A' <= 1 && "LL" not allowed
		return (checkRecordUtil(0, 0, "L", n) + checkRecordUtil(0, 1, "A", n) + checkRecordUtil(0, 0, "P", n)) % mod;
	}

  private:
	int checkRecordUtil(int index, int a, string prevTwo, int n) {
		// cout << index << " " << a << " " << prevTwo << " " << n << "\n";
		if (index == n - 1) {
			return 1;
		}
		int x = 0;
		if (a == 0) {
			// cout << prevTwo << " " << prevTwo[1] << "\n";
			if (prevTwo.size() == 2) {
				x = checkRecordUtil(index + 1, a + 1, prevTwo[1] + 'A', n);
			} else {
				x = checkRecordUtil(index + 1, a + 1, "A", n);
			}
		}
		int y = 0;
		if (prevTwo != "LL") {
			if (prevTwo.size() == 2) {
				y = checkRecordUtil(index + 1, a, prevTwo[1] + "L", n);
			} else {
				y = checkRecordUtil(index + 1, a, "L", n);
			}
		}
		int z = 0
		if (prevTwo.size() == 2) {
			z = checkRecordUtil(index + 1, a, prevTwo[1] + "P", n);
		} else {
			z = checkRecordUtil(index + 1, a, "P", n);
		}
		return (x + y + z) % mod;
	}
};