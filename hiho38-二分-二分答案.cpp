// #1139 : 二分·二分答案
// http://hihocoder.com/problemset/problem/1139
/*
    对于索敌值w进行二分搜索，索敌值低于l无法到达t， 高于r可以到达t，当l+1 == r则找到所需要的最小索敌值
    因为需要在k步到达，所以需要用bfs，dfs因为有环所以不适合
*/
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
const int N = 1e5+7;
const int M = 1e5+7;
const int W = 1e6+7;
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

bool f[W];
bool visited[N];
int n, m, k, t;
int ans = 0;
void init() {
    scanf("%d%d%d%d", &n, &m, &k, &t);
    int u, v, c;
    rep (i, m) {
        scanf("%d%d%d", &u, &v, &c);
        g.addedge(u, v, c);
        g.addedge(v, u, c);
    }
}

bool bfs(int w) {
    queue<pair<int, int> > qu;
    qu.push(make_pair(1, 0));
    while (!qu.empty()) {
        pair<int, int> pr = qu.front();
        qu.pop();
        int u = pr.first;
        int d = pr.second;
        if (u == t)
            return true;
        if (d == k)
            continue;
        visited[u] = true;
        for (int i = g.head[u]; ~i; i = g.edge[i].next) {
            int v = g.edge[i].to;
            if (visited[v] || g.edge[i].cost > w)
                continue;
            qu.push(make_pair(v, d+1));
        }        
    }
    return false;
}

void solve() {
    memset(f, false, sizeof (f));
    int l = 0, r = W-1;
    f[l] = false, f[r] = true;
    while (l+1 < r) {
        memset(visited, false, sizeof(visited));
        int mid = (l+r)/2;
        if (bfs(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    ans = r;
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
	return 0;
}
