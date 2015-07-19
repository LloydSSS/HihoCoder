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

int heap[N];
int heap_size = 0;

//下滑操作
void siftdown(int start = 1, int end = heap_size) {
    //将start号结点向下调整直到end
    int i = start, j = 2*i;
    heap[0] = heap[i]; //用heap[0]来临时保存i结点的值
    while(j <= end) {
        //有右孩子并且右孩子比左孩子小时，将j保存右孩子
        if(j<end && heap[j]<heap[j+1]) ++j;
        //比j号结点小时，不需调整
        if(heap[0] >= heap[j])
            break;
        else {
            //向下调整
            heap[i] = heap[j];
            i = j;
            j = 2*j;
        }
    }
    heap[i] = heap[0];
}

//向上调整的函数
//将结点start调整到根结点1为止
void siftup(int start = heap_size) {
    int j = start, i=j/2;
    heap[0] = heap[j];
    while(j > 0) {
        if(heap[i] >= heap[0])
            break;
        else {
            //向上调整工作
            heap[j] = heap[i];
            j = i;
            i = i/2;
        }
    }
    heap[j] = heap[0];
}

//生成大根堆
void makeheap(int n) {
    int pos = n/2; //找到开始调整的位置(即最后一个结点双亲的位置)
    while(pos > 0) {
        siftdown(pos, n);
        --pos;
    }
}

//插入操作的实现
void heappush(int x) {
    ++heap_size;
    heap[heap_size]=x;
    siftup(heap_size);
}

//删除操作
int heappop() {
    int retv = heap[1];
    heap[1] = heap[heap_size]; //填补树根
    --heap_size;
    siftdown(1); //将根结点下滑到尾部
    return retv;
}

int n;
void solve() {
    scanf("%d", &n);
    char nl;
    char op;
    int num;
    rep (i, n) {
        scanf("%c", &nl);
        scanf("%c", &op);
        if (op == 'A') {
            scanf("%d", &num);
            heappush(num);
        } else
            printf("%d\n", heappop());
    }
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/HihoCoder/in.txt", "r", stdin);
#else
    freopen("D:/Project/HihoCoder/in.txt", "r", stdin);
#endif
#endif

    solve();
    return 0;
}
