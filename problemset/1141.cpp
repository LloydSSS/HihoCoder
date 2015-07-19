// #1141 : 二分·归并排序之逆序对
// http://hihocoder.com/problemset/problem/1141
/*
    plan A: 归并排序 在merge时计算逆序对
    plan B: 树状数组
*/
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
const int W = 1e6+7;
const int L = 1e2+7;

int a[N];
int n;
ll ans = 0;
void init() {
    scanf("%d", &n);
    rep (i, n) {
        scanf("%d", a+i);
    }
}

int tmp[N];
void merge (int l, int m, int r) {
    int i = l, j = m, k = l;
    while (i < m || j < r) {
        if (j == r || (i < m && a[i] <= a[j]))
            tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            ans += m-i;
        }
    }
    for (k = l; k < r; ++k)
        a[k] = tmp[k];
}

void mergesort(int l, int r) {
    if (l == r || l+1 == r)
        return;

    int m = (l+r)/2;

    mergesort(l, m);
    mergesort(m, r);
    merge(l, m, r);
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
    mergesort(0, n);
    printf("%lld\n", ans);
    return 0;
}
