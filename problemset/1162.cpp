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
const int N = 2<<7;
const int M = 1e5+7;
const int L = 1e2+7;
const int MOD = 12357;

struct Matrix {
    int mat[N][N];
    int m;
    Matrix(int m_) : m(m_) {
        makeZero();
    }
    void makeUnit() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j)
                mat[i][j] = (i == j);
        }
    }
    void makeZero() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j)
                mat[i][j] = 0;
        }
    }

    void copy(Matrix &des) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j)
                des.mat[i][j] = mat[i][j];
        }
    }

    Matrix multiply(const Matrix &rhs) {
        Matrix retv(m);
        for (int z = 0; z < m; ++z)
        {
            for (int i = 0; i < m; ++i)
            {
                if (mat[i][z] == 0) continue;
                for (int j = 0; j < m; ++j)
                {
                    retv.mat[i][j] += mat[i][z] * rhs.mat[z][j];
                    if (retv.mat[i][j] >= MOD)
                        retv.mat[i][j] %= MOD;
                }
            }
        }
        return retv;
    }

    Matrix pow(int t) {
        Matrix retv(m), tmp = *this, tmp2(m);
        retv.makeUnit();
        while (t) {
            if (t & 1) {
                tmp2 = tmp.multiply(retv);
                tmp2.copy(retv);
            }
            tmp = tmp.multiply(tmp);
            t >>= 1;
        }
        return retv;
    }
};

int n, k;
int ans = 0;
Matrix d(N);
void dfs(int x, int y, int col) {
    if (col == k) {
        d.mat[x][y] = 1;
        return;
    }
    dfs(x << 1, (y << 1) + 1, col + 1);
    dfs((x << 1) + 1, y << 1, col + 1);
    if (col + 2 <= k)
        dfs((x << 2) + 3, (y << 2) + 3, col + 2);
}

void solve() {
    d.m = 1<<k;
    dfs(0, 0, 0);
    Matrix mt = d.pow(n);
    ans = mt.mat[mt.m-1][mt.m-1];
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif
    scanf("%d%d", &k, &n);
    solve();
    printf("%d\n", ans);
    return 0;
}
