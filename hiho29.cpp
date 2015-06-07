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
#include <climits>
#include <utility>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

typedef long long ll;
const double eps = 1e-9;
const int N = 1e5+7;
const int M = 1e6+7;
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
int ans = 0;
bool visited[N];

void input() {
    scanf("%d%d", &n, &m);
    int u, v, c;
    rep (i, m) {
        scanf("%d%d%d", &u, &v, &c);
        g.addedge(u, v, c);
        g.addedge(v, u, c);
    }
    memset(visited, 0, sizeof(visited));
}

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void HeapPrim() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    pq.push(make_pair(1, 0));
    while (!pq.empty()) {
        pair<int, int> pr = pq.top();
        pq.pop();
        int u = pr.first;
        int c = pr.second;
        if (visited[u])
            continue;
        visited[u] = true;
        ans += c;
        for (int i = g.head[u]; ~i; i = g.edge[i].next) {
            int v = g.edge[i].to;
            if (visited[v])
                continue;
            pq.push(make_pair(v, g.edge[i].cost));
        }
    }
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
    HeapPrim();
    printf("%d\n", ans);
    return 0;
}
