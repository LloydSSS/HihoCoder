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

const int maxN = 101010;
pair<int, int> a[maxN], b[maxN];

int main() {
    freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
	int t, m, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		rep(i, n)
			scanf("%d%d", &a[i].first, &a[i].second);
		rep(i, m)
			scanf("%d%d", &b[i].first, &b[i].second);
		sort(a, a+n);
		sort(b, b+m);
		long long ans = 0, cnt = 0;
		int j = 0;
		rep(i, n) {
			while (j < m && a[i].first > b[j].first) {
				cnt += b[j].second;
				j++;
			}
			ans += cnt * a[i].second;
		}
		printf("%lld\n", ans);
	}
    return 0;
}
