//hiho 1142
//三分搜索，注意dist非凸，需要根据输入x限定搜索范围
#include <iostream>
#include <vector>
#include <string>
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

double a, b, c, x, y;
double ans;

double func(double n) {
	return a*n*n+b*n+c;
}

double dist(double n) {
	return sqrt((x-n)*(x-n)+(func(n)-y)*(func(n)-y));
}

void solve() {
//d = min{sqrt((X - x)^2+(aX^2+bX+c-y)^2)}
	double l = -1e5, r = 1e5;
	double m = -b/(2.0*a);
	if (x > m) l = m;
	else r = m;
	while (fabs(r-l)>eps) {
		double lm = l + (r-l)/3;
		double rm = r - (r-l)/3;
		if (dist(lm) < dist(rm)) {
			r = rm;
		} else {
			l = lm;
		}
	}
	ans = dist(l);
}

int main() {
    freopen("D:/Baogui/Project/HihoCoder/in.txt", "r", stdin);
    scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &x, &y);
    solve();
    printf("%.3lf\n", ans);
    return 0;
}
