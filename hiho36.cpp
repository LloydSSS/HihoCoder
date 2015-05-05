#include <iostream>
#include <vector>
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
const int N = 1000010;
ll num[N];
int main() {
    freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
	ll n, k;
	scanf("%lld%lld", &n, &k);
	rep(i, n) scanf("%lld", &num[i]);
	int pos = 0;
	for (; pos < n; ++pos) {
		if (num[pos] == k)
			break;
	}
	if (pos == n) {
		printf("-1\n");
		return 0;
	}
	int l = 0, r = n-1;
	while (l < r) {
		while (num[l] < num[pos])
			l++;
		if (num[l] != num[pos]) 
			swap(num[l], num[pos]);
		pos = l;
		while (num[pos] < num[r])
			r--;
		if (num[pos] != num[r])
			swap(num[pos], num[r]);
		pos = r;
	}
	printf("%d\n", pos+1);
    return 0;
}
