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

//hashmap
struct hashnode {
    char str[L];
    int key;
    struct hashnode *next;
} nodes[N << 1], *hashtable[N];

int hashid = 0;
int hashfind(int hashkey, char *s)
{
    struct hashnode *node;
    for (node = hashtable[hashkey]; node && strcmp(node->str, s); node = node->next)
        ;
    return node == NULL ? -1 : (node - nodes);
}

int hashinsert(int hashkey, char *s, int key)
{
    strcpy(nodes[hashid].str, s);
    nodes[hashid].key = key;
    nodes[hashid].next = hashtable[hashkey];
    hashtable[hashkey] = &nodes[hashid];
    return hashid++;
}

int hashcode(char *str)
{
    unsigned int seed = 13131; // 31 131 1313 13131 131313 ..
    unsigned int hash = 0;
    while (*str)
        hash = hash * seed + (*str++);
    return (hash & 0x7FFFFFFF);
}

void init() {

}

void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    init();
    solve();
    return 0;
}

