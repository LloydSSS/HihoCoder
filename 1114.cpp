#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

const int N = 100010;
int a[N], b[N], c[N];

bool check(int x, int n) {
    b[0] = x;
    b[1] = a[0] - b[0];
    if (b[1] < 0 || b[1] > 1) return false;
    rep_st(i, 1, n) {
        b[i+1] = a[i] - b[i] - b[i-1];
        if (b[i+1] < 0 || b[i+1] > 1) return false;
    }
    if (b[n] != 0) return false;
    return true;
}

int main() {
    freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", &a[i]);
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));

        int cnt = 0;
        if (check(0, n)) {
            cnt++;
            rep(i, n) c[i] += b[i];
        }
        if (check(1, n)) {
            cnt++;
            rep(i, n) c[i] += b[i];
        }

        int k = 0;
        rep(i, n) if (c[i] == cnt) k++;
        printf("%d", k);
        rep(i, n) if (c[i] == cnt) printf(" %d", i+1);
        printf("\n");

        k = 0;
        rep(i, n) if (c[i] == 0) k++;
        printf("%d", k);
        rep(i, n) if (c[i] == 0) printf(" %d", i+1);
        printf("\n");
    }
    return 0;
}
