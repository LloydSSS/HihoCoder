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
	//int sum;
};

struct segmentTree {
	stNode nodes[N<<2];
	bool visited[N<<2];
	int sum;

	segmentTree() {
		memset(visited, false, sizeof(visited));
		sum = 0;
	}

	void build(int idx, int l, int r) {
		nodes[idx].left = l;
		nodes[idx].right = r;
		nodes[idx].set = 0;
		if (l < r) {
			int mid = (l+r)/2;
			build(idx<<1, l, mid);
			build(idx<<1|1, mid+1, r);
		}
	}

	void pushdown(int idx) {
		if (nodes[idx].set) {
			nodes[idx<<1].set = nodes[idx].set;
			nodes[idx<<1|1].set = nodes[idx].set;
			nodes[idx].set = 0;
		}
	}

	void update(int idx, int l, int r, int v) {
		if (nodes[idx].left>=l && nodes[idx].right<=r) {
			nodes[idx].set = v;
		}
		else {
			pushdown(idx);
			int mid = (nodes[idx].left+nodes[idx].right)/2;
			if (l<=mid) {
				update(idx<<1, l, r, v);
			}
			if (mid<r) {
				update(idx<<1|1, l, r, v);
			}
		}
	}

	void query(int idx, int l, int r) {
		if (nodes[idx].set) {
			if (!visited[nodes[idx].set])
				sum++;
			visited[nodes[idx].set] = true; 
		}
		else if ( nodes[idx].left < nodes[idx].right) {
			int mid = (nodes[idx].left+nodes[idx].right)/2;
			if (l <= mid) {
				query(idx<<1, l, r);
			}
			if (mid < r) {
				query(idx<<1|1, l, r);
			}
		}
	}
}st;

int n, m, x, y;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	//freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
	freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

	scanf ("%d%d", &n, &m);

	vector<int> vec;
	vector<pair<int, int> > post;
	map<int, int> mp;
	rep (i, n) {
		scanf("%d%d", &x, &y);
		post.push_back(make_pair(x, y));
		vec.push_back(x);
		vec.push_back(y);
		//st.update(x, y, i, 1, m, 1);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	rep (i, vec.size()) {
		mp[vec[i]] = i+1;
	}

	m = vec.size();
	st.build(1, 1, m);
	rep (i, n) {
		st.update(1, mp[post[i].first], mp[post[i].second]-1, i+1);
	}
	st.query(1, 1, m);
	printf("%d\n", st.sum);
	return 0;
}
