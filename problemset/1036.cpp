#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)

class trie {
public:
	int size;
	trie *suffix;
	trie *next[26];
	trie() {
		size = 0;
		suffix = NULL;
		memset(next, 0, sizeof(next));
	}
};

void insert(trie *root, string s) {
	trie *cur = root;
	rep(i, s.size()) {
		int id = s[i]-'a';
		if (cur->next[id] == NULL) {
			trie *nn = new trie();
			cur->next[id] = nn;
		}
		cur = cur->next[id];
	}
	cur->size++;
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
    trie *root = new trie();
    while (n--) {
		cin >> s;
        insert(root, s);
    }

	root->suffix = root;
	queue<trie *> q;
	rep(i,26){
		if(!root->next[i])
			root->next[i] = root;
		else{
			root->next[i]->suffix=root;
			q.push(root->next[i]);
		}
	}

	while (!q.empty()) {
		trie *cur = q.front();
		trie *suf = cur->suffix;
		q.pop();
		rep(i, 26){
			if(!cur->next[i]){
				cur->next[i] = suf->next[i];
			}else{
				cur->next[i]->suffix = suf->next[i];
				q.push(cur->next[i]);
			}
		}
	}

    cin >> s;
	trie *cur = root;
	bool found = false;
	rep(i, s.size()) {
		int id=s[i]-'a';
		cur=cur->next[id];
		if(cur->size > 0) {
			found = true;
			break;
		}
	}
	if (found)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

    return 0;
}
