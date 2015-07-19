//hiho#1127 : 二分图三·二分图最小点覆盖和最大独立集
//最小点覆盖的点数 = 二分图最大匹配
//最大独立集的点数 = 总点数 - 二分图最大匹配
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
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
const int N = 1e4+7;
const int M = 1e4+7;
const int L = 1e2+7;

// Graph
struct graphedge {
    int to;         // 表示指向的节点
    int cost;       // 权重
    int next;       // 模拟指针，初始化为0
    graphedge() {
        to = 0, cost = 0, next = 0;
    }
};

struct graph {
    int head[N]; // 表示头指针，初始化为0
    graphedge edge[M<<1];
    int edgecnt;

    graph() {
        memset(head, -1, sizeof(head));
        edgecnt = 0;
    }

    void addedge(int from, int to, int cost = 0) {    // 添加边(from, to) cost
        edge[edgecnt].to = to;
        edge[edgecnt].cost = cost;
        edge[edgecnt].next = head[from];
        head[from] = edgecnt++;
    }

    void func() {
        // 枚举边的过程，u为起始点
        int u = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            //
        }
    }
} g;

int n, m;
int record[N];
bool visited[N];
int ans = 0;
void init() {
    scanf("%d%d", &n, &m);
    int u, v;
    rep (i, m) {
        scanf("%d%d", &u, &v);
        g.addedge(u, v);
        g.addedge(v, u);
    }
}

bool find_path(int u) {
    for (int i = g.head[u]; ~i; i = g.edge[i].next) {
        int v = g.edge[i].to;
        if (visited[v])
            continue;
        visited[v] = true;
        if (record[v] == 0 || find_path(record[v])) {
            record[u] = v;
            record[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    memset(record, 0, sizeof(record));
    rep_st (i, 1, n+1) {
        if (record[i] == 0) {
            memset(visited, 0, sizeof(visited));
            find_path(i);
        }
    }
    rep_st (i, 1, n+1) {
        if (record[i] != 0)
            ans++;
    }
    ans = ans/2;
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    init();
	solve();
    printf("%d\n", ans);
    printf("%d\n", n - ans);
	return 0;
}
