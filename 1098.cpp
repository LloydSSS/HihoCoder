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



int p[N];
int find_p(int x) {
    if (x != p[x])
        p[x] = find_p(p[x]);
    return p[x];
}

void union1(int x, int y) {
    p[find_p(x)] = find_p(p[y]);
}

bool judge(int x, int y) {
    return find_p(x) == find_p(y);
}

struct edge {
    int u;
    int v;
    int val;
}e[M];

int n, m;
int ans = 0;

bool cmp(const edge &a, const edge &b) {
    return a.val < b.val;
}

void input() {
    scanf("%d%d", &n, &m);
    rep (i, m)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].val);
}

void Kruskal() {
    rep(i, n+1)
        p[i] = i;
    sort(e, e+m, cmp);
    rep(i, m) {
        if (judge(e[i].u, e[i].v))
            continue;
        union1(e[i].u, e[i].v);
        ans += e[i].val;
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
    Kruskal();
    printf("%d\n", ans);
    return 0;
}
