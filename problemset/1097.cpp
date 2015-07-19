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
const int N = 1e3+7;
const int M = 1e4+7;
const int L = 1e2+7;

int n;
int cost[N][N];
int ans = 0;
bool visited[N];

void input() {
    scanf("%d", &n);
    rep (i, n)
    rep (j, n)
    scanf("%d", &cost[i][j]);
    memset(visited, 0, sizeof(visited));
}

void Prim() {
    int min_cost[N];
    rep (i, n)
    min_cost[i] = cost[0][i];
    visited[0] = true;
    rep (i, n-1) {
        int c = INT_MAX;
        int mj = -1;
        rep(j, n) {
            if (!visited[j] && min_cost[j] < c) {
                mj = j;
                c = min_cost[j];
            }
        }
        visited[mj] = true;
        ans += c;
        rep(j, n) {
            if (!visited[j] && cost[j][mj] < min_cost[j]) {
                min_cost[j] = cost[j][mj];
            }
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
    Prim();
    printf("%d\n", ans);
    return 0;
}
