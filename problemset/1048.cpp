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
const int MOD = 1000000007;

int n, m;
int ans = 0;
int dp[N][1<<5];
//dp[i][j] = x 表示使第i 行状态为j 的方法总数为x

//state 由上一行决定的这一行必须放置竖向瓷砖的地方，state的二进制表示中的1 就是这些地方
//pre_sum, row-1行出发状态为~state的方法数
void dfs(int row, int col, int state, int pre_sum) {
    if (col == m) {
        dp[row][state] = (dp[row][state]+pre_sum)%MOD;
        return;
    }

    // 该列不放置
    dfs(row, col+1, state, pre_sum);

    // 横放
    if ((col < m-1) && !(state & (1<<col)) && !(state & (1<<(col+1))))
        dfs(row, col+2, state|(1<<col)|(1<<(col+1)), pre_sum);
}

void solve() {
    bool cur = 0;

    dfs(0, 0, 0, 1);
    rep_st (i, 1, n) {
        rep (j, (1<<m)) {
            if (dp[i-1][j] == 0)
                continue;
            dfs(i, 0, (~j)&((1<<m)-1), dp[i-1][j]); 
        }
    }
    ans = dp[n-1][(1<<m)-1];
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    scanf("%d%d", &n, &m);
    if (n < m) {
        swap(n, m);
    }
    if ((n*m)%2 == 0) {
        solve();
    }
    printf("%d\n", ans);

	return 0;
}
