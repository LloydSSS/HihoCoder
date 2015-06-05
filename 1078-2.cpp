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
	int sum;
};

struct segmentTree {
	stNode nodes[N<<2];
	bool visited[N<<2];

	segmentTree() {
		memset(visited, false, sizeof(visited));
	}

	void build(int idx, int l, int r) {
		nodes[idx].left = l;
		nodes[idx].right = r;
		nodes[idx].set = -1;
		nodes[idx].sum = 0;
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
		if (nodes[idx].set != -1) {
			nodes[idx<<1].set = nodes[idx<<1|1].set = nodes[idx].set;
			nodes[idx<<1].sum = nodes[idx<<1].set*(nodes[idx<<1].right-nodes[idx<<1].left+1);
			nodes[idx<<1|1].sum = nodes[idx<<1|1].set*(nodes[idx<<1|1].right-nodes[idx<<1|1].left+1);
			nodes[idx].set = -1;
		}
	}

	void update(int idx, int l, int r, int v) {
		if (nodes[idx].left >= l && nodes[idx].right <= r) {
			nodes[idx].set = v;
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

	scanf ("%d", &n);
	st.build(1, 1, n);

	scanf("%d", &m);
	rep (i, m) {
		int op;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 0) {
			printf("%d\n", st.query(1, x, y));
		} else {
			int v;
			scanf("%d", &v);
			st.update(1, x, y, v);
		}
	}
	return 0;
}
