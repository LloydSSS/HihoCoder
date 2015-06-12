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
const int N = 1e4+7;
const int M = 1e6+7;
const int L = 1e6+7;

char s[L], p[L];
int nt[L];
void get_next (char *p, int *nt) {
	int i = 0, j = -1;
	nt[0] = -1;
	while (i < strlen(p)) {
		if (j == -1 || p[i] == p[j]) {
			nt[++i] = ++j;
		} else {
			j = nt[j];
		}
	}
}

int kmp(char *s, char *p) {
	get_next(p, nt);
	int i = 0, j = 0;
	int ans = 0;
	int slen = strlen(s);
	int plen = strlen(p);
	while (i < slen) {
		if (j == -1 || s[i] == p[j]) {
			++i;
			++j;
		} else {
			j = nt[j];
		}
		if (j == plen) {
			//printf("match:%d\n", i-j);
			++ans;
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif
    int n;
    scanf("%d", &n);
    while (n--) {
    	scanf("%s", p);
    	scanf("%s", s);
		printf("%d\n", kmp(s, p));
    }
    return 0;
}
