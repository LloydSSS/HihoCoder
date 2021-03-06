//hiho#1122 : 二分图二•二分图最大匹配之匈牙利算法
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

int record[1010];
bool used[1010];
bool find_path(int x, vector<set<int> > &graph) {
    //虚线
    for (set<int>::iterator sit = graph[x].begin(); sit != graph[x].end(); sit++) {
        int y = *sit;
        if (used[y] == true)
            continue;
        used[y] = true;
        //实线
        if (record[y] == 0 || find_path(record[y], graph)) {
            record[y] = x;
            record[x] = y;
            return true;
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif
    int n, m, u, v, ans = 0;
    scanf("%d %d", &n, &m);
    vector<set<int> > graph(n+1);
    memset(record, 0, sizeof(record));
    rep(i, m) {
        scanf("%d %d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }
    rep_st(i, 1, n+1) {
        memset(used, 0, sizeof(used));
        if (record[i] == 0)
            find_path(i, graph);
    }

    rep_st(i, 1, n+1) {
        if (record[i] != 0)
            ans++;
    }
    printf("%d\n", ans/2);
    return 0;
}
