#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007LL
#define PI 2 * acos(0)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class DSU {
private :
	vector<int> parent;
	vector<int> rank;
public :
	DSU(int n) {
		rank.assign(n, 0);
		parent.assign(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int findSet(int u) {
		return (parent[u] == u) ? u : (parent[u] = findSet(u));
	}
	bool isSameSet(int u, int v) {
		return findSet(u) == findSet(v);
	}
	void unionSet(int u, int v) {
		if (!isSameSet(u, v)) {
			int a = findSet(u);
			int b = findSet(v);
			if (rank[a] > rank[b]) {
				parent[b] = a;
			} else {
				parent[a] = b;
				if (rank[a] == rank[b]) {
					rank[b]++;
				}
			}
		}
	}
};

class SegmentTree {
private :
	vector<int> st;
	vector<int> A;
	int n;

	int left(int i) {
		return i << 1;
	}

	int right(int i) {
		return (i << 1) + 1;
	}

	void build(int p, int L, int R) {
		if (L == R) {
			st[p] = L;
		} else {
			int M = L + (R - L) / 2;
			build(left(p), L, M);
			build(right(p), M + 1, R);
			int p1 = st[left(p)];
			int p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}

	int query(int p, int L, int R, int i, int j) {
		if (i > R || j < L) {
			return -1;
		}
		if (L >= i && R <= j) {
			return st[p];
		}
		int M = L + (R - L) / 2;
		int p1 = query(left(p), L, M, i, j);
		int p2 = query(right(p), M + 1, R, i, j);
		if (p1 == -1) {
			return p2;
		}
		if (p2 == -1) {
			return p1;
		}
		return (A[p1] <= A[p2]) ? p1 : p2;
	}

public :
	SegmentTree(const vector<int> &_A) {
		A = _A;
		n = (int) A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}
	int query(int i, int j) {
		return query(1, 0, n - 1, i, j);
	}
}

void solve()
{
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}
