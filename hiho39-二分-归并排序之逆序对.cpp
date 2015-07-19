// #1141 : 二分·归并排序之逆序对
// http://hihocoder.com/problemset/problem/1141
/*
    plan A: 归并排序 在merge时计算逆序对
    plan B: 树状数组
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

typedef long long ll;
const ll mod=1000000007;
const int N = 100010;

int num[N], tmp[N];
int n;

ll solve(int l, int r) {
	if (l == r || l + 1 == r)
		return 0;
	int m = (l+r)>>1;

	int result = solve(l, m) + solve(m, r);
	int i = l, j = m, k = l;
	while (i < m || j < r) {
		if (j != r && (num[i] > num[j] || i == m)) {
			result += m-i;
			tmp[k] = num[j];
			j++;
		} else if (i!=m){
			tmp[k] = num[i];
			i++;
		}
		k++;
	}
	rep_st(i, l, r)
		num[i] = tmp[i];
	return result;
}

int main() {
	//freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, n) scanf("%d", &num[i]);
	printf("%ld\n", solve(0, n));
	return 0;
}
