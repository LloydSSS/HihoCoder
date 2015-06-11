#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <ctime>
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
const int N = 1e7+7;
const int M = 1e5+7;
const int L = 1e2+7;

int a[N];
int n, k;
int ans = -1;
int partition(int l, int r, int pivot) {
    while (l < r) {
        while (a[l] < a[pivot]) l++;
        swap(a[l], a[pivot]);
        pivot = l;
        while (a[r] > a[pivot]) r--;
        swap(a[r], a[pivot]);
        pivot = r;
    }
    return pivot; 
}

void solve() {
    if (k > n)
        return;

    srand(time(0));
    int l = 0, r = n-1, pivot = 0;
    while (true) {
        pivot = l + rand()%(r-l+1);
        pivot = partition(l, r, pivot);
        if (pivot == k-1)
            break;
        if (pivot > k-1)
            r = pivot-1;
        else
            l = pivot+1;

    }
    ans = a[pivot];
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    scanf("%d%d", &n, &k);
    rep (i, n) scanf("%d", &a[i]);
    solve();
    printf("%d\n", ans);
    return 0;
}
