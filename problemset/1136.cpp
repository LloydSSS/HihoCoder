//hiho 1136 拓扑排序
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
const int MAXM = 100010;
const int MAXN = 100010;
const int mod = 142857;

int head[ MAXN + 1] = {0};	// 表示头指针，初始化为0
int p[ MAXM + 1];		// 表示指向的节点
int ne[ MAXM + 1] = {0}; 	// 模拟指针，初始化为0
int edgecnt = 0;			// 记录边的数量

int t, n, m, k, x, y;
int signals[MAXN];
vector<int> startby[MAXN];
int deg[MAXN];
int emit[MAXN][4];
int ans[MAXN];

void addedge(int u, int v) {	// 添加边(u,v)
	++edgecnt;
	p[ edgecnt ] = v;
	ne[ edgecnt ] = head[u];
	head[u] = edgecnt;
}

void init() {
    edgecnt = 0;
    memset(deg, 0, sizeof (deg));
    memset(head, 0, sizeof (head));
    memset(p, 0, sizeof (p));
    memset(ne, 0, sizeof (ne));
    memset(deg, 0, sizeof (deg));
    memset(ans, 0, sizeof (ans));

    rep (i, n) {
        for (int j = 0; emit[i][j] != -1; ++j) {
            int s = emit[i][j];
            rep (l, startby[s].size()) {
                addedge(i, startby[s][l]);
                deg[startby[s][l]]++;
            }
        }
    }
    rep (i, m) {
        int s = signals[i];
        rep (l, startby[s].size()) {
            ans[startby[s][l]]++;
        }
    }
}

void solve() {
    queue<int> que;

    rep (i, n) {
        if (deg[i] == 0)
            que.push(i);
    }

    while (!que.empty()) {
        x = que.front();
        que.pop();
        // 枚举边的过程，u为起始点
        for (int i = head[x]; i; i = ne[i]) {
            y = p[i];
            ans[y] = (ans[x]+ans[y])%mod;
            deg[y]--;
            if (deg[y] == 0)
                que.push(y);
        }
    }
}

int main() {
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    scanf("%d", &t);
    while (t--) {
        memset(emit, -1, sizeof (emit));
        scanf("%d%d", &n, &m);
        rep (i, n) startby[i].clear();
        rep (i, m) scanf("%d", &signals[i]);
        rep (i, n) {
            scanf("%d", &x);
            startby[x].push_back(i);
            scanf("%d", &k);
            rep (j, k) {
                scanf("%d", &emit[i][j]);
            }
        }
        init();
        solve();
        rep (i, n-1)
            printf("%d ", ans[i]);
        printf("%d\n", ans[n-1]);
    }
    return 0;
}
