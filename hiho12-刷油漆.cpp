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
#define rrep_st(i,s,t) for (int i = t-1; i >= s; --i)

typedef long long ll;
const double eps = 1e-9;
const int N = 1e2+7;
const int M = 1e2+7;
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
int weight[N];
int ans = 0;
int f[N][M];

void input() {
    memset(f, 0, sizeof(f));

    scanf("%d%d", &n, &m);
    rep (i, n)
        scanf("%d", &f[i+1][1]);
    int u, v;
    rep (i, n-1) {
        scanf("%d%d", &u, &v);
        g.addedge(u, v);
        g.addedge(v, u);
    }
}

void dfs(int fa, int u) {
    for (int i = g.head[u]; ~i; i = g.edge[i].next) {
        int v = g.edge[i].to;
        if (v == fa)
            continue;
        dfs(u, v);
    }

    for (int i = g.head[u]; ~i; i = g.edge[i].next) {
        int v = g.edge[i].to;
        if (v == fa)
            continue;
        rrep_st (mi, 2, m+1) {
            rep_st (j, 1, mi) {
                f[u][mi] = max(f[u][mi], f[u][mi-j] + f[v][j]);
            }
        }
    }
}


void solve() {
    dfs(0, 1);
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    input();
    solve();
    printf("%d\n", f[1][m]);
    return 0;
}

