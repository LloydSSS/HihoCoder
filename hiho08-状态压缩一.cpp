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
const int N = 1e3+7;
const int M = 1e5+7;
const int L = 1e2+7;

int n, m, q;
int w[N];
int ans = 0;
void init() {
    scanf("%d%d%d", &n, &m, &q);
    rep(i, n) scanf("%d", &w[i]);
}

int bit_count(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x = x&(x-1);
    }
    return cnt;
}

int dp[N][1<<10];
void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][1<<(m-2)] = w[0];
    rep_st (i, 1, n) {
        rep (j, 1<<m) {

            int state = (j>>1);
            if (dp[i][state] < dp[i-1][j])
                dp[i][state] = dp[i-1][j];

            state = (j>>1)|(1<<(m-2));
            if (bit_count(j) < q) {
                if (dp[i][state] < dp[i-1][j] + w[i])
                    dp[i][state] = dp[i-1][j] + w[i];
            }

            if (dp[i][j] > ans)
                ans = dp[i][j];
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

    init();
	solve();
    printf("%d\n", ans);
	return 0;
}
