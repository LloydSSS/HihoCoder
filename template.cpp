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

/*
// Graph
struct graphedge {
    int to;         // 表示指向的节点
    int cost;       // 权重
    int next;       // 模拟指针，初始化为0
    graphedge() {
        to = 0, cost = 0, next = 0;
    }
};

struct graph {
    int head[N]; // 表示头指针，初始化为0
    graphedge edge[M<<1];
    int edgecnt;

    graph() {
        memset(head, -1, sizeof(head));
        edgecnt = 0;
    }

    void addedge(int from, int to, int cost = 0) {    // 添加边(from, to) cost
        edge[edgecnt].to = to;
        edge[edgecnt].cost = cost;
        edge[edgecnt].next = head[from];
        head[from] = edgecnt++;
    }

    void func() {
        // 枚举边的过程，u为起始点
        int u = 0;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            //
        }
    }
} g;
*/

/*
// tree
struct treenode {
    int firstson;
    int nextbro;
    treenode() : firstson(-1), nextbro(-1) {}
};
*/

/*
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
*/

void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif

	solve();
	return 0;
}
