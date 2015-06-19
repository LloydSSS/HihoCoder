// #1032 : 最长回文子串
// http://hihocoder.com/problemset/problem/1032
/*
	O(n^3)	枚举每个子串，判断是否是回文子串
	O(n^2)	中心扩展 or DP
	O(n)	Manacher 纪录可以扩展到最右的回文子串的中心
*/
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
const int N = 1e6+7;
const int M = 1e6+7;
const int L = 1e2+7;

string convert(string s) {
    string t = "#";
    rep (i, s.size()) {
        t += s[i];
        t += "#";
    }
    return t;
}

int expandAroundCenter(string s) {
    if (s.size() == 0)
        return 0;
    int max_len = 1;
    string t = convert(s);
    rep (i, t.size()) {
        int len = 1;
        while (i-len >= 0 && i+len < t.size() && t[i-len] == t[i+len])
            len++;
        len = len-1;
        if (len > max_len)
            max_len = len;

    }
    return max_len;
}

int Manacher(string s) {
    if (s.size() == 0)
        return 0;
    int max_len = 1;
    string t = convert(s);
    vector<int> p(t.size());
    int center = 0;		//目前能延伸到最右的位置回文子串的中心
    int mx = 0;			//目前回文子串所能延伸到最右的位置
    rep (i, t.size()) {
        p[i] = 1;
        if (mx > i)
        	p[i] = min(p[2*center-i], mx-i);
        while (i-p[i] >= 0 && i+p[i] < t.size() && t[i-p[i]] == t[i+p[i]])
        	p[i]++;
        p[i] = p[i]-1;
        if (i+p[i] > mx) {
        	mx = i+p[i];
        	center = i;
        }
        if (p[i] > max_len)
            max_len = p[i];
    }
    return max_len;
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
    string s;
    scanf("%d", &n);
    while (n--) {
        cin>>s;
        //int lenA = expandAroundCenter(s);
        int lenB = Manacher(s);
        printf("%d\n", lenB);
    }
    return 0;
}
