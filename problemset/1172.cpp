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

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif
    int n;
    string s;
    cin >> n;
    cin >> s;
    int xsum = 0;
    rep (i, n) {
        if (s[i] == 'H')
            xsum ^= i+1;
    }
    if (xsum) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
