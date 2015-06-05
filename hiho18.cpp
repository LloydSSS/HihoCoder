#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <climits>
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
const int N = 1000010;
const int M = 100010;
const int L = 101;

int n, m, op, x, y;

int A[N];
int minv[N<<2];
void build(int L, int R, int o) {
    if (L == R) {
        minv[o] = A[L];
        return;
    }
    int M = (L+R)/2;
    build(L, M, o*2);
    build(M+1, R, o*2+1);
    minv[o] = min(minv[o*2], minv[o*2+1]);
}

int query(int o, int L, int R, int ql, int qr) {
    int M = (L+R)/2, retv = INT_MAX;
    if (ql <= L && R <= qr) return minv[o];                     // include
    if (ql <= M) retv = min(retv, query(o*2, L, M, ql, qr));    // turn left
    if (M < qr) retv = min(retv, query(o*2+1, M+1, R, ql, qr)); // trun right
    return retv;
}

void update(int o, int L, int R, int p, int v) {
    if (L == R)
        minv[o] = v; //leaf node
    else {
        int M = (L+R)/2;
        // first update children
        if (p <= M) update(o*2, L, M, p, v);
        else update(o*2+1, M+1, R, p, v);
        // update cur node
        minv[o] = min(minv[o*2], minv[o*2+1]);
    }
}

int main() {
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    //freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
    scanf ("%d", &n);

    rep_st(i, 1, n+1)
        scanf("%d", &A[i]);

    build(1, n, 1);

    scanf("%d", &m);
    rep (i, m) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 0)
            printf("%d\n", query(1, 1, n, x, y));
        else {
            A[x] = y;
            update(1, 1, n, x, y);
        }
    }
    return 0;
}
