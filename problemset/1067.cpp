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

int p[N];
int find_p(int x) {
	if (x != p[x])
    	p[x] = find_p(p[x]);
	return p[x];
}

void union1(int x, int y) {
    p[find_p(y)] = find_p(x);
}

struct treenode {
	int firstson;
	int nextbro;
	treenode() : firstson(-1), nextbro(-1) {}
};

int n, m;
vector<int> result(N);
vector<list<int> > rlist(N);
vector<pair<int, int> > req(N); 
vector<bool> visited(N, false);
vector<string > namevec(N);
vector<treenode> tree(N);

void dfs(int id) {
    visited[id] = true;
    int id1 = tree[id].firstson;
    while(id1 != -1) {
        dfs(id1);
        union1(id, id1);
        id1 = tree[id1].nextbro;
    }
    for(list<int>::iterator it = rlist[id].begin(); it != rlist[id].end(); ++it)
        if(result[*it] == 0)
        {
            if(req[*it].first == id)
                id1 = req[*it].second;
            else
                id1 = req[*it].first;
            if(visited[id1])
                result[*it] = find_p(id1);
        }
    return;
}

int main() {
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
    
    string a, b;
	int ia, ib, cnt = 1;
    map<string, int> mp;

	scanf("%d", &n);
	rep (i, n+1) {
		p[i] = i;
	}

	rep (i, n) {
        cin >> a >> b;
        ia = mp[a];
        ib = mp[b];
        if (ia == 0) {
            mp[a] = cnt;
            namevec[cnt] = a;
            ia = cnt;
            cnt++;
        }
        if (ib == 0) {
            mp[b] = cnt;
            namevec[cnt] = b;
            ib = cnt;
            cnt++;
        }

        tree[ib].nextbro = tree[ia].firstson;
        tree[ia].firstson = ib;
	}

	scanf ("%d", &m);
	rep (i, m) {
        cin >> a >> b;
        ia = mp[a];
        ib = mp[b];       
        if (ia == ib)
            result[i] = ia;
        else {
            req[i] = make_pair(ia, ib);
            rlist[ia].push_back(i);
            rlist[ib].push_back(i);
        }		
	}

    dfs(1);
    for (int i = 0; i < m; ++i)
        cout << namevec[result[i]] << endl;
	return 0;
}
