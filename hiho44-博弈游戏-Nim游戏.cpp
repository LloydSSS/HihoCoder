#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

typedef long long ll;
const ll mod=1000000007;
const int N = 1000010;

int num[N];
int n = 0;
bool ans = false;

void solve() {
    int xsum = num[0];
    rep_st(i, 1, n)
        xsum ^= num[i];
    if (xsum != 0)
        ans = true;
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
    rep(i, n) scanf("%d", &num[i]);
    solve();
    if (ans) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
