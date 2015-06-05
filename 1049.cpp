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
const int M = 1e5+7;
const int L = 1e2+7;

string solve(string pre, string in) {
    if (pre.size() <= 1)
        return pre;
    char rt = pre[0];
    size_t pos = in.find_first_of(rt);
    return solve(pre.substr(1, pos), in.substr(0, pos-1))
    + solve(pre.substr(pos+1), in.substr(pos+1)) + rt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    //freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
    string preorder;
    string inorder;
    cin >> preorder >> inorder;
    cout << solve(preorder, inorder) << endl;
    return 0;
}
