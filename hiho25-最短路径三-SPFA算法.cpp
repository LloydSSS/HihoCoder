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

int n, m, s, t;

struct qnode {
    int pos;
    int cost;
    qnode(int p, int c) : pos(p), cost(c) {}
    bool operator< (const qnode &rhs) const {
        return cost > rhs.cost;
    }
};

int dist[N];
void Dijstra() {
    memset(dist, -1, sizeof(dist));
    priority_queue<qnode> pq;
    pq.push(qnode(s, 0));
    while (!pq.empty() && dist[t] == -1) {
        qnode qn = pq.top();
        pq.pop();
        if (dist[qn.pos] != -1)
            continue;
        dist[qn.pos] = qn.cost;

        int u = qn.pos;
        for (int i = g.head[u]; ~i; i = g.edge[i].next) {
            int v = g.edge[i].to;
            if (dist[v] != -1)
                continue;
            pq.push(qnode(v, dist[u] + g.edge[i].cost));
        }
    }
}

void spfa() {
    memset(dist, -1, sizeof(dist));
    queue<int> qu;
    dist[s] = 0;
    qu.push(s);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int i = g.head[u]; ~i; i = g.edge[i].next) {
            int v = g.edge[i].to;
            if (dist[v] == -1 || dist[v] > dist[u] + g.edge[i].cost) {
                dist[v] = dist[u] + g.edge[i].cost;
                qu.push(v);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    //freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, c;
    rep (i, m) {
        scanf("%d%d%d", &u, &v, &c);
        g.addedge(u, v, c);
        g.addedge(v, u, c);
    }
	spfa();
    printf("%d\n", dist[t]);
	return 0;
}
