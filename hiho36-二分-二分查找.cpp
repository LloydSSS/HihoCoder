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
const int N = 1e7+7;
const int M = 1e5+7;
const int L = 1e2+7;

int a[N];
int n, k;
int ans = -1;
void solve() {
    int pos = 0;
    while (pos < n) {
        if (a[pos] == k)
            break;
        pos++;
    }
    if (pos == n)
        return;

    int l = 0, r = n-1;
    while (l < r) {
        while (a[l] < k) l++;
        while (a[r] > k) r--;
        if (l != r)
	        swap(a[l], a[r]);
    }
    ans = l+1;
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
