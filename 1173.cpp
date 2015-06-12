// #1173 : 博弈游戏·Nim游戏·三
// http://hihocoder.com/problemset/problem/1173
/*
	因为数的范围比较大，所以最好通过SG打表的结果找出规律在解。
	sg(4k)=4k-1;sg(4k+1)=4k+1;sg(4k+2)=4k+2;sg(4k+3)=4k+4;
*/
#include <iostream>
#include <vector>
#include <queue>
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
const int N = 1e6+7;
const int M = 1e5+7;
const int L = 1e2+7;
const int MOD = 12357;

int sg[N];
int getSG(int x) {
	int mex[1000];
    memset(mex, 0, sizeof(mex));
    if(sg[x] != -1)
    	return sg[x];
    for(int i=x-1;i>=0;i--) {
        mex[getSG(i)]=1;
    }
    for(int i=1; i<=x/2; i++) {
        int ans=0;
        ans ^= getSG(i);
        ans ^= getSG(x-i);
        mex[ans] = 1;
    }
    for(int i=0;;i++)
    	if(!mex[i])
    		return sg[x]=i;
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
	memset(sg, -1, sizeof(sg));
	for (int i = 0; i < 100; ++i) {
		printf("sg[%d] = %d\n", i, getSG(i));
	}
#endif

	int n, x, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if(x%4 == 0)  ans ^= (x-1);
		else if(x%4 == 1)  ans ^= x;
		else if(x%4 == 2) ans ^= x;
		else ans ^= (x+1);
	}
    if (ans) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
