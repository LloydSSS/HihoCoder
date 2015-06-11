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
const int M = 1e5+7;
const int L = 1e2+7;


int n;
int pyramid[N][N];
int dp[N];
int ans = 0;
void init() {
    scanf("%d", &n);
    rep (i, n) {
        rep (j, i+1) {
            scanf("%d", &pyramid[i+1][j+1]);
        }
    }
}

void solve() {
    memset(dp, 0, sizeof(dp));
    rep_st (i, 1, n+1) {
        rrep_st (j, 1, i+1)
            dp[j] = max(dp[j], dp[j-1]) + pyramid[i][j];
    }
    rep (i, n)
    ans = max(ans, dp[i+1]);
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
