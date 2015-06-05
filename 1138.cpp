#include <iostream>
#include <vector>
#include <queue>
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
const int N = 100010;
ll num[N];

struct node {
    ll x;
    ll y;

} nd[N];

vector<map<ll, ll> > road(N);
vector<bool> visited(N);
vector<int> dist(N, INT_MAX);

int n, s, t;

void spfa() {
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    visited[s] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (std::map<ll,ll>::iterator p = road[u].begin(); p != road[u].end(); ++p) {
            ll v = p->first;
            ll l = p->second;
            if (dist[v] > dist[u] + l) {
                dist[v] = dist[u] + l;
                que.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    scanf("%d", &n);
    rep(i, n) scanf("%lld%lld", &nd[i].x, &nd[i].y);
    rep(i, n) {
        rep_st(j, i+1, n) {
            road[i][j] = road[j][i] = min(abs(nd[i].x-nd[j].x), abs(nd[i].y-nd[j].y));
        }
    }

    s = 0;
    t = n-1;
    spfa();
    printf("%d\n", dist[t]);
    return 0;
}

