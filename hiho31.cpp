#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

const int num = 1000;
int m, n;
int puz[num][num];
int sov[num][num];
int di[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int di2[8][2] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

void check1() {
	rep_st(i, 1, n+1) {
		rep_st(j, 1, m+1) {
			if (puz[i][j] == 0) {
				rep(k, 8) {
					int u = i+di[k][0];
					int v = j+di[k][1];
					if (puz[u][v] == -1)
						sov[u][v] = 1;
				}
			}
		}
	}	
}

void check2() {
	rep_st(i, 1, n+1) {
		rep_st(j, 1, m+1) {
			if (puz[i][j] > 0) {
				int cnt = 0;
				rep(k, 8) {
					if (puz[i+di[k][0]][j+di[k][1]] == -1)
						cnt++;
				}
				if (cnt == puz[i][j]) {
					rep(k, 8) {
						int u = i+di[k][0];
						int v = j+di[k][1];
						if (puz[u][v] == -1)
							sov[u][v] = 2;
					}
				}
			}
		}
	}	
}

void check3() {
	rep_st(i, 1, n+1) {
		rep_st(j, 1, m+1) {
			if (puz[i][j] != -1) {
				int cnt1 = 0;
				rep(k, 8) {
					if (puz[i+di[k][0]][j+di[k][1]] == -1)
						cnt1++;
				}
				rep(k, 8) {
					int x = i+di2[k][0];
					int y = j+di2[k][1];

					if (puz[x][y] != -1) {
						int cnt2 = 0;
						rep(l, 8) {
							if (puz[x+di[l][0]][y+di[l][1]] == -1)
								cnt2++;
						}

						if (puz[i][j] - puz[x][y] == cnt1 - cnt2) {
							if (puz[i][j] - puz[x][y] == 0) continue;
							int a, b, c, d;
							if (puz[i][j] - puz[x][y] > 0) {
								a = i, b = j, c = x, d = y;
							} else {
								a = x, b = y, c = i, d = j;
							}
							bool contain = true;
							rep(l, 8) {
								int u = c+di[l][0];
								int v = d+di[l][1];
								if (puz[u][v] == -1) {
									if (abs(u-a) > 1 || abs(v-b) > 1) {
										contain = false;
										break;
									}
								}
							}
							if (contain) {
								rep(l, 8) {
									int u = a+di[l][0];
									int v = b+di[l][1];
									if (puz[u][v] == -1) {
										if (abs(u-c) > 1 || abs(v-d) > 1) {
											sov[u][v] = 2;
										}
									}
								}
							}
						} 
					}
				}
			}
		}
	}	
}

int main() {
    freopen("D:/Baogui/Code/hiho/in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(puz, 0, sizeof(puz));
		memset(sov, 0, sizeof(sov));
		scanf("%d%d", &n, &m);
		rep(i, n) 
		rep(j, m)
			scanf("%d", &puz[i+1][j+1]);

		check1();
		check2();
		check3();
		int cnt1 = 0, cnt2 = 0;
		rep(i, n)
		rep(j, m) {
			if (sov[i+1][j+1] == 2)
				cnt1++;
			if (sov[i+1][j+1] == 1)
				cnt2++;
		}
		printf("%d\n%d\n", cnt1, cnt2);
	}
    return 0;
}
