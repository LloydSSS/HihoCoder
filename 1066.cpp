#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
const int N = 20010;

int p[N];
int find_p(int x) {
    if (x != p[x])
        p[x] = find_p(p[x]);
    return p[x];
}

void union1(int x, int y) {
    p[find_p(x)] = find_p(p[y]);
}

bool judge(int x, int y) {
    return find_p(x) == find_p(y);
}


int main() {
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
	map<string, int> mp;
	int n, op, cnt = 0;
	int ia, ib;
	string a, b;

	cin >> n;
	rep (i, N) {
		p[i] = i;
	}
	while (n--) {
		cin>>op>>a>>b;
		if (mp.find(a) == mp.end())
			mp[a] = cnt++;
		if (mp.find(b) == mp.end())
			mp[b] = cnt++;
		ia = mp[a];
		ib = mp[b];
		if (op == 0)
			p[find_p(ia)] = find_p(ib);
		else if (find_p(ia) == find_p(ib))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
