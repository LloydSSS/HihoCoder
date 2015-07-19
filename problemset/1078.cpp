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

int n, m, op, x, y;
int A[N];

struct SegmentTree {
    int c[N<<2];
    int delay[N<<2];
    
    void pushup(int rt) {
        c[rt] = c[rt<<1]+c[rt<<1|1];
    }
    
    void pushdown(int rt,int len) {
        if(delay[rt] != -1) {
            delay[rt<<1] = delay[rt<<1|1] = delay[rt];
            c[rt<<1] = delay[rt]*(len-(len>>1));
            c[rt<<1|1] = delay[rt]*(len>>1);
            delay[rt] = -1;
        }
    }
    
    void build(int l, int r, int rt) {
        delay[rt] = -1;
        if(l == r) {
        	c[rt] = A[l];
            //scanf("%d",&c[rt]);
            return ;
        }
        int m = (l+r)>>1;
        build(l, m, rt<<1);
        build(m+1, r, rt<<1|1);
        pushup(rt);
    }
    
    void update(int L,int R,int x,int l,int r,int rt) {
        if(L<=l && r<=R) { ///No delay before.
            delay[rt] = x;
            c[rt] = x*(r-l+1);
            return ;
        }
        pushdown(rt, r-l+1);
        int m = (l+r)>>1;
        if(L <= m) update(L, R, x, l, m, rt<<1);
        if(m < R) update(L, R, x, m+1, r, rt<<1|1);
        pushup(rt);
    }
    
    int query(int L,int R,int l,int r,int rt)
    {
        if(L<=l && r<=R)
            return c[rt];
        pushdown(rt, r-l+1);
        int m = l+r>>1;
        int res = 0;
        if(L <= m) res += query(L, R, l, m, rt<<1);
        if(m < R) res += query(L, R, m+1, r, rt<<1|1);
        return res;
    }
}st;


int main() {
#ifndef ONLINE_JUDGE
	//freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
	freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
	scanf ("%d", &n);

	rep_st(i, 1, n+1)
		scanf("%d", &A[i]);

	st.build(1, n, 1);

	scanf("%d", &m);
	rep (i, m) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 0) {
			printf("%d\n", st.query(x, y, 1, n, 1));
		} else {
			int v;
			scanf("%d", &v);
			st.update(x, y, v, 1, n, 1);
		}
	}
	return 0;
}
