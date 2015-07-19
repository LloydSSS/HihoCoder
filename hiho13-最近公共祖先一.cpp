#include <iostream>
#include <vector>
#include <string>
#include <queue>
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


void solve() {

}

int main() {
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
	map<string, string> mp;
	int n, m;
	string a, b;
	cin>>n;
	while (n--) {
		cin>>a>>b;
		mp[b] = a;
	}
	cin>>m;
	while (m--) {
		cin>>a>>b;
		set<string> fam;
		string ans = "-1";
		fam.insert(a);
		while (mp.find(a) != mp.end()) {
			a = mp[a];
			fam.insert(a);
		}
		while (true) {
			if (fam.find(b) != fam.end()) {
				ans = b;
				break;
			}
			if (mp.find(b) != mp.end())
				b = mp[b];
			else
				break;
		}
		cout << ans << endl;
	}
	return 0;
}
