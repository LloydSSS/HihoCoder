//hiho 48

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
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
const int MAXN = 100010;
const int MAXM = 500050;

int head[ MAXN + 1] = {0};	// 表示头指针，初始化为0
int p[ MAXM + 1];		// 表示指向的节点
int ne[ MAXM + 1] = {0}; 	// 模拟指针，初始化为0
int edgecnt = 0;			// 记录边的数量

void addedge(int u, int v) {	// 添加边(u,v)
	++edgecnt;
	p[ edgecnt ] = v;
	ne[ edgecnt ] = head[u];
	head[u] = edgecnt;
}

const int mod = 142857;
int m, n, k;
ll ans = 0;
int deg[MAXN] = {0};
ll virus[MAXN] = {0};

void solve() {
	queue<int> que;
	rep_st(i, 1, n+1) {
		if (deg[i] == 0)
			que.push(i);
	}

	int popcnt = 0;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		popcnt++;
		ans = (ans + virus[u])%mod;
		// 枚举边的过程，u为起始点
		for (int i = head[u]; i; i = ne[i]) {
			int v = p[i];
			deg[v]--;
			virus[v] = (virus[v] + virus[u])%mod;
			if (deg[v] == 0) {
				que.push(v);
			}
		}
	}
}

int main() {
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);

	scanf("%d%d%d", &n, &m, &k);
	int v;
	rep (i, k) {
		scanf("%d", &v);
		virus[v] = 1;
	}

	edgecnt = 0;
	memset(deg, 0, sizeof (deg));
	memset(head, 0, sizeof (head));
	memset(p, 0, sizeof (p));
	memset(ne, 0, sizeof (ne));

	int a, b;
	rep(i, m) {
		scanf("%d%d", &a, &b);
		addedge(a, b);
		deg[b]++;
	}
	solve();
	printf("%lld\n", ans);
    return 0;
}
