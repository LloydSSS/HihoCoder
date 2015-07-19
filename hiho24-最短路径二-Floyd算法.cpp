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
const int M = 1e4+7;
const int L = 1e2+7;

int n, m;

int dist[N][N];

void Floyd() {

    rep_st (k, 1, n+1) {
        rep_st (i, 1, n+1) {
            rep_st (j, 1, n+1) {
                if (i != j && i != k && j != k) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    //freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    rep_st (i, 1, n+1) {
        rep_st (j, 1, n+1) {
            dist[i][j] = 10010;
        }
        dist[i][i] = 0;
    }

    int u, v, c;
    rep (i, m) {
        scanf("%d%d%d", &u, &v, &c);
        if (dist[u][v] < c)
            continue;
        dist[u][v] = dist[v][u] = c;
    }
	Floyd();
    rep_st (i, 1, n+1) {
        rep_st (j, 1, n) {
            printf("%d ", dist[i][j]);
        }
        printf("%d\n", dist[i][n]);
    }
	return 0;
}
