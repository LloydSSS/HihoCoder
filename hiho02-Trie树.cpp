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
const int N = 1e5+7;
const int M = 1e6+7;
const int L = 1e2+7;

struct TrieNode {
	int cnt;
	int next[26];
	TrieNode() : cnt(0) {
		memset(next, -1, sizeof(next));
	}
};

struct TrieTree {
	TrieNode node[M];
	int node_cnt;
	TrieTree () : node_cnt(1) {}

	void insert(char *s) {
		for (int i = 0, p = 0; s[i]; ++i) {
			int x = s[i] - 'a';
			if (node[p].next[x] == -1) {
				node[p].next[x] = node_cnt++;
			}
			p = node[p].next[x];
			node[p].cnt++;
		}
	}

	int query(char *s) {
		int p = 0;
		for (int i = 0; s[i]; ++i) {
			int x = s[i] - 'a';
			if (node[p].next[x] == -1) {
				return 0;
			}
			p = node[p].next[x];
		}
		return node[p].cnt;
	}
}trie;

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif
    int n, m;
    char str[L];
    scanf("%d", &n);
    while (n--) {
    	scanf("%s", str);
    	trie.insert(str);
    }
    scanf("%d", &m);
    while (m--) {
		scanf("%s", str);
    	printf("%d\n", trie.query(str));
    }
    return 0;
}
