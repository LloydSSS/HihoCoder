#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <utility>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

typedef long long ll;
const double eps = 1e-9;
const int N = 1e5+7;
const int M = 1e5+7;
const int L = 1e2+7;

struct stNode {
	int left;
	int right;
	int set;
	int add;
	int sum;
};

struct segmentTree {
	stNode nodes[N<<2];

	segmentTree() {
	}

	void build(int idx, int l, int r) {
		nodes[idx].left = l;
		nodes[idx].right = r;
		nodes[idx].set = -1;
		nodes[idx].add = 0;
		if (l == r) {
			scanf("%d", &nodes[idx].sum);
			return;
		}
		if (l < r) {
			int mid = (l+r)/2;
			build(idx<<1, l, mid);
			build(idx<<1|1, mid+1, r);
			pushup(idx);
		}

	}

	void pushup(int idx) {
		nodes[idx].sum = nodes[idx<<1].sum + nodes[idx<<1|1].sum;
	}

	void pushdown(int idx) {
		if (nodes[idx].left == nodes[idx].right)
			return;
		if (nodes[idx].set != -1) {
			nodes[idx<<1].set = nodes[idx<<1|1].set = nodes[idx].set;
			nodes[idx<<1].add = nodes[idx<<1|1].add = 0;
			nodes[idx<<1].sum = nodes[idx<<1].set*(nodes[idx<<1].right-nodes[idx<<1].left+1);
			nodes[idx<<1|1].sum = nodes[idx<<1|1].set*(nodes[idx<<1|1].right-nodes[idx<<1|1].left+1);
			nodes[idx].set = -1;
		}
		if (nodes[idx].add != 0) {
			nodes[idx<<1].add += nodes[idx].add;
			nodes[idx<<1|1].add += nodes[idx].add;
			nodes[idx<<1].sum += nodes[idx].add*(nodes[idx<<1].right-nodes[idx<<1].left+1);
			nodes[idx<<1|1].sum += nodes[idx].add*(nodes[idx<<1|1].right-nodes[idx<<1|1].left+1);
			nodes[idx].add = 0;
		}
	}

	void update(int idx, int l, int r, int v) {
		if (nodes[idx].left >= l && nodes[idx].right <= r) {
			nodes[idx].set = v;
			nodes[idx].add = 0;
			nodes[idx].sum = v*(nodes[idx].right-nodes[idx].left+1);
		} else {
			pushdown(idx);
			int mid = (nodes[idx].left+nodes[idx].right)/2;
			if (l<=mid) {
				update(idx<<1, l, r, v);
			}
			if (mid<r) {
				update(idx<<1|1, l, r, v);
			}
			pushup(idx);
		}
	}

	void updateadd(int idx, int l, int r, int v) {
		if (nodes[idx].left >= l && nodes[idx].right <= r) {
			nodes[idx].add += v;
			nodes[idx].sum += v*(nodes[idx].right-nodes[idx].left+1);
		} else {
			pushdown(idx);
			int mid = (nodes[idx].left+nodes[idx].right)/2;
			if (l<=mid) {
				updateadd(idx<<1, l, r, v);
			}
			if (mid<r) {
				updateadd(idx<<1|1, l, r, v);
			}
			pushup(idx);
		}
	}

	int query(int idx, int l, int r) {
		if (nodes[idx].left >= l && nodes[idx].right <= r) {
			return nodes[idx].sum;
		} else if ( nodes[idx].left < nodes[idx].right) {
			pushdown(idx);
			int retv = 0;
			int mid = (nodes[idx].left+nodes[idx].right)/2;
			if (l <= mid) {
				retv += query(idx<<1, l, r);
			}
			if (mid < r) {
				retv += query(idx<<1|1, l, r);
			}
			return retv;
		}
	}
}st;

int n, m, x, y;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	//freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
	freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

	scanf ("%d%d", &n, &m);
	st.build(1, 1, n+1);

	rep (i, m) {
		int op, v;
		scanf("%d%d%d%d", &op, &x, &y, &v);
		if (op == 0) {
			st.updateadd(1, x+1, y+1, v);
			printf("%d\n", st.query(1, 1, n+1));
		} else {
			st.update(1, x+1, y+1, v);
			printf("%d\n", st.query(1, 1, n+1));
		}
	}
	return 0;
}
