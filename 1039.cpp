#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string del(string s) {
	string t = "^";
	for (int i = 1; i < s.size()-1; ++i) {
		if (s[i] != s[i-1] && s[i] != s[i+1])
			t += s[i];
	}
	t += "$";
	return t;
}

int main() {
	//freopen("C:\\Users\\ch5-1112\\Desktop\\in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
		s = "^"+s+"$";
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            for (char c = 'A'; c <= 'C'; ++c) {
                string ns = s;
                ns.insert(i, 1, c);
                int size = ns.size();
                while (true) {
					
                    ns = del(ns);
                    if (ns.size() < size) {
                        size = ns.size();
                    } else
                        break;
                }
                if (s.size() - size + 1 > ans)
                    ans = s.size() - size + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}