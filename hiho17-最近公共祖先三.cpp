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

struct treenode {
    int firstson;
    int nextbro;
    treenode() : firstson(-1), nextbro(-1) {}
};

int n, m;
vector<string > name(N);
vector<treenode> tree(N);
vector<int> lastvisit(N);
vector<int> depth(N);
vector<vector<int> > rmq(N<<1, vector<int>(20));
int did = 0;

int log_two(int x) {
    int j = 0;
    while ((1<<(j+1)) < x) {
        j++;
    }
    return j;
}

void build() {
    int n = did;
    int k = log_two(n);
    rep_st (j, 1, k+1) {
        rep(i, n-(1<<(j-1))) {
            if (depth[rmq[i][j-1]] < depth[rmq[i+(1<<(j-1))][j-1]]) {
                rmq[i][j] = rmq[i][j-1];
            } else {
                rmq[i][j] = rmq[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int ST(int l, int r) {
    int j = log_two(r-l+1);
    if (depth[rmq[l][j]] < depth[rmq[r-(1<<j)+1][j]])
        return rmq[l][j];
    return rmq[r-(1<<j)+1][j];
}

void dfs(int id, int d) {
    depth[id] = d;
    rmq[did][0] = id, lastvisit[id] = did;
    did++;

    int id1 = tree[id].firstson;
    while(id1 != -1) {
        dfs(id1, d+1);
        id1 = tree[id1].nextbro;

        rmq[did][0] = id, lastvisit[id] = did;
        did++;
    }
}

int main() {
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
    
    string a, b;
    int ia, ib, cnt = 1;
    map<string, int> mp;

    scanf("%d", &n);

    rep (i, n) {
        cin >> a >> b;
        ia = mp[a];
        ib = mp[b];
        if (ia == 0) {
            mp[a] = cnt;
            name[cnt] = a;
            ia = cnt;
            cnt++;
        }
        if (ib == 0) {
            mp[b] = cnt;
            name[cnt] = b;
            ib = cnt;
            cnt++;
        }

        tree[ib].nextbro = tree[ia].firstson;
        tree[ia].firstson = ib;
    }

    dfs(1, 0);
    build();

    scanf ("%d", &m);
    rep (i, m) {
        cin >> a >> b;
        ia = mp[a];
        ib = mp[b];   
        if (ia == ib)
            cout << name[ia] << endl;
        else {
            int l = lastvisit[ia];
            int r = lastvisit[ib];
            if (l > r)
                swap(l, r);
            int f = ST(l, r);
            cout << name[f] << endl;
        }       
    }

    return 0;
}
