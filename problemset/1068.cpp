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
const int N = 100010;
const int M = 100010;
const int L = 101;

int n, k, m;
int ans;
int l, r;

int find_j(int n) {
    int j = 0;
    while ((1<<(j+1)) < n) {
        j++;
    }
    return j;
}

void build(vector<vector<int> > &weight) {
    rep_st (j, 1, k+1) {
        rep(i, n-(1<<(j-1))) {
            weight[i][j] = min(weight[i][j-1], weight[i+(1<<(j-1))][j-1]);
        }
    }
}

int ST(vector<vector<int> > &weight, int l, int r) {
    int j = find_j(r-l+1);
    return min(weight[l][j], weight[r-(1<<j)+1][j]);
}

int main() {
    //freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
    scanf ("%d", &n);
    k = find_j(n);

    vector<vector<int> > weight(n+1, vector<int>(k+1));

    rep(i, n)
        scanf("%d", &weight[i][0]);
    
    build(weight);
    scanf("%d", &m);
    rep (i, m) {
        scanf("%d%d", &l, &r);
        ans = ST(weight, l-1, r-1);
        printf("%d\n", ans);
    }
    return 0;
}
