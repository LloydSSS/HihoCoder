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

int n, m;
int deg[N];
bool ans = false;

void input() {
    scanf("%d%d", &n, &m);

    rep (i, n)
        p[i+1] = i+1;

    int u, v;
    rep (i, m) {
        scanf("%d%d", &u, &v);
        union1(u, v);
        deg[u]++;
        deg[v]++;
    }
}

void solve() {
    int odd = 0;
    rep (i, n) {
        if (deg[i+1]%2)
            odd++;
    }
    if (odd != 0 && odd != 2) {
        ans = false;
        return;
    }
    rep (i, n) {
        if (!judge(1, i+1)) {
            ans = false;
            return;
        }
    }
    ans = true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    //freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

    input();
    solve();
    if (ans)
        printf("Full\n");
    else
        printf("Part\n");

	return 0;
}
