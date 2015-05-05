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

typedef long long ll;
const ll mod=1000000007;
ll dp[110][110][110];
int main() {
    freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
    int t, m, n;
    scanf("%d", &t);
    while (t--) {
	    scanf("%d%d", &n, &m);
	    memset(dp, 0, sizeof(dp));
	    dp[0][m][0] = 1;
	    dp[0][m-1][1] = m;
	    dp[0][m-2][2] = m*(m-1)/2
	    // (1) 全0 
	    // (2.1) 1个1，在某个原先和为0的列中
	    // (2.2) 1个1，在某个原先和为1的列中
	    // (3.1) 2个1，两列原先和为0 
	    // (3.2) 2个1，一列原先和为0，一列原先和为1 
	    // (3.3) 2个1，两列原先和为1 
	    // (4) 1个2。
	    rep_st(i, 1, n) {
	    	rep(x, m) {
	    		rep (y, m-j) {

	    		}
	    	}
	    }
	}
    return 0;
}
