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
const int N = 1e3+7;
const int M = 1e5+7;
const int L = 1e2+7;

int n, m;
int need[N];
int value[N];
int dp[2][M];
int ans = 0;
void init() {
    scanf("%d%d", &n, &m);
    rep (i, n)
        scanf("%d%d", &need[i+1], &value[i+1]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    bool cur = 0;
    rep_st (i, 1, n+1) {
        cur = !cur;
        rep (j, m+1) {
            if (j < need[i])
                dp[cur][j] = dp[!cur][j];
            else
                dp[cur][j] = max(dp[!cur][j], dp[!cur][j-need[i]]+value[i]);
        }
    }
    ans = dp[cur][m];
}

int dp1d[M];
void solve1d() {
    memset(dp1d, 0, sizeof(dp1d));
    rep_st (i, 1, n+1) {
        rrep_st (j, need[i], m+1)
            dp1d[j] = max(dp1d[j], dp1d[j-need[i]] + value[i]);
    }
    ans = dp1d[m];
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
    solve1d();
    printf("%d\n", ans);
    return 0;
}
