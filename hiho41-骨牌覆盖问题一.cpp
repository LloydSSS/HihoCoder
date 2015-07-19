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
const int MOD = 19999997;

void cal(long long a[2][2],long long b[2][2]) {
    long long c[2][2];
    c[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
    c[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
    c[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
    c[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
    a[0][0]=c[0][0];
    a[0][1]=c[0][1];
    a[1][0]=c[1][0];
    a[1][1]=c[1][1];
}

int n;
ll ans = 0;
void solve() {
    ll a[2][2] = {0, 1, 1, 1};
    ll r[2][2] = {1, 0, 0, 1};
    while (n) {
        if (n&1)
            cal(r, a);
        cal(a, a);
        n >>= 1;
    }
    ans = r[1][1];
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif
    scanf("%d", &n);
    solve();
    printf ("%lld\n", ans);
    return 0;
}
