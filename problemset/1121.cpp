#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

int record[10010];
bool paint(int x, vector<set<int> > &graph) {
	for (set<int>::iterator sit = graph[x].begin(); sit != graph[x].end(); sit++) {
		int y = *sit;
		if (record[y] == 0) {
			record[y] = -record[x];
			if (!paint(y, graph))
				return false;
		} else if (record[y] == record[x]) {
			return false;
		}
	}
	return true;
}

int main() {
    freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
	int t, n, m, u, v;
	bool success;
	scanf("%d", &t);
	while (t--) {
		success = true;
		memset(record, 0, sizeof(record));
		scanf("%d %d", &n, &m);
		vector<set<int> > graph(n+1);
		rep(i, m) {
			scanf("%d %d", &u, &v);
			graph[u].insert(v);
			graph[v].insert(u);
		}
		rep_st(i, 1, n+1) {
			if (record[i] == 0) {
				record[i] = -1;
				if (!paint(i, graph)) {
					success = false;
					break;
				}
			}
		}
		if (success)
			printf("Correct\n");
		else
			printf("Wrong\n");
	}
	return 0;
}
