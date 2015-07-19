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
const int MOD = 12357;

void cal(ll a[][8], ll b[][8])
{
    ll t[8][8]={0};
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            for(int k=0;k<8;k++) t[i][j]=(t[i][j]+a[i][k]*b[k][j])%MOD;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++) a[i][j]=t[i][j];
}

int n;
ll ans = 0;
void solve() {
    ll m[8][8] = {  0, 0, 0, 0, 0, 0, 0, 1,
                    0, 0, 0, 0, 0, 0, 1, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 1, 0, 0, 1,
                    0, 0, 0, 1, 0, 0, 0, 0,
                    0, 0, 1, 0, 0, 0, 0, 0,
                    0, 1, 0, 0, 0, 0, 0, 1,
                    1, 0, 0, 1, 0, 0, 1, 0};
    ll r[8][8] = {  1, 0, 0, 0, 0, 0, 0, 0,
                    0, 1, 0, 0, 0, 0, 0, 0,
                    0, 0, 1, 0, 0, 0, 0, 0,
                    0, 0, 0, 1, 0, 0, 0, 0,
                    0, 0, 0, 0, 1, 0, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 0, 0, 1, 0,
                    0, 0, 0, 0, 0, 0, 0, 1};
    while (n) {
        if (n&1)
            cal(r, m);
        cal(m, m);
        n >>= 1;
    }
    ans = r[7][7];
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
