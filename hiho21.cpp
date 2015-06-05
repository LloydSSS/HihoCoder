#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <climits>
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

int n, m, x, y;
int A[N] = {0};

set<int> alived;
struct SegmentTree {
    int delay[N<<2];
    bool vis[N<<2];
    
    SegmentTree() {
        memset(delay, -1, sizeof(delay));
        memset(vis, false, sizeof(vis));
    }

    void pushdown(int rt,int len) {
        if(delay[rt] != -1) {
            delay[rt<<1] = delay[rt<<1|1] = delay[rt];
            delay[rt] = -1;
        }
    }
    
    void update(int L,int R,int x,int l,int r,int rt) {
        if(L<=l && r<=R) { ///No delay before.
            delay[rt] = x;
            return ;
        }
        pushdown(rt, r-l+1);
        int m = (l+r)>>1;
        if(L <= m) update(L, R, x, l, m, rt<<1);
        if(m < R) update(L, R, x, m+1, r, rt<<1|1);
    }
    
    int query(int l,int r,int rt) {
        if (delay[rt] != -1) {
            if (vis[delay[rt]])
                return 0;
            vis[delay[rt]] = true;
            return 1;
        }
        if (l == r) return 0;
        pushdown(rt, r-l+1);
        int m = (l+r)>>1;
        int res = 0;
        res += query(l, m, rt<<1);
        res += query(m+1, r, rt<<1|1);
        return res;
    }

    void dfs(int l, int r, int rt) {
        if (delay[rt] != -1) {
            alived.insert(delay[rt]);
        }
        if (l == r) return;
        pushdown(rt, r-l+1);
        int m = (l+r)>>1;
        dfs(l, m, rt<<1);
        dfs(m+1, r, rt<<1|1);
    }
}st;


int main() {
#ifndef ONLINE_JUDGE
    //freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

    scanf ("%d%d", &n, &m);

    vector<int> vec;
    vector<pair<int, int> > post;
    map<int, int> mp;
    rep (i, n) {
        scanf("%d%d", &x, &y);
        post.push_back(make_pair(x, y));
        vec.push_back(x);
        vec.push_back(y);
        //st.update(x, y, i, 1, m, 1);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    rep (i, vec.size()) {
        mp[vec[i]] = i+1;
    }

    m = vec.size();
    rep (i, n) {
        st.update(mp[post[i].first], mp[post[i].second]-1, i, 1, m, 1);
    }

    // st.dfs(1, m, 1);
    // cout << alived.size() << endl;
    cout << st.query(1, m, 1) << endl;
    return 0;
}
