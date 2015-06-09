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
const int M = 1e5+7;
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
        init();
    }

    void init() {
        memset(head, -1, sizeof(head));
        edgecnt = 0;
    }

    void addedge(int from, int to, int cost = 0) {    // 添加边(from, to) cost
        edge[edgecnt].to = to;
        edge[edgecnt].cost = cost;
        edge[edgecnt].next = head[from];
        head[from] = edgecnt++;
    }

} g;

int t, n, m;
bool ans = false;
int record[N];

bool paint(int u) {
    // 枚举边的过程，u为起始点
    for (int i = g.head[u]; ~i; i = g.edge[i].next) {
        int v = g.edge[i].to;
        if (record[v] == 0) {
            record[v] = -record[u];
            if (!paint(v))
                return false;
        } else if (record[v] == record[u])
            return false;

    }
    return true;
}
void solve() {
    memset(record, 0, sizeof(record));
    rep_st (i, 1, n+1) {
        if (record[i] == 0) {
            record[i] = 1;
            ans = paint(i);
            if (!ans) 
                return;
        }
    }
    ans = true;
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    scanf("%d", &t);
    int u, v;
    while (t--) {
        scanf("%d%d", &n, &m);
        g.init();
        rep (i, m) {
            scanf("%d%d", &u, &v);
            g.addedge(u, v);
            g.addedge(v, u);
        }
        solve();
        if (ans)
            printf("Correct\n");
        else
            printf("Wrong\n");
    }
	return 0;
}
