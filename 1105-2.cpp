#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <stdio.h>
using namespace std;
int main () {
    //freopen("D:/Baogui/in.txt", "r", stdin);
    int n;
    vector<int > v;
    make_heap(v.begin(), v.end());
    scanf("%d", &n);
    while (n--) {
        char action;
        char nl;
        int val;
        scanf("%c", &nl);
        scanf("%c", &action);
        if (action == 'A') {
            scanf("%d", &val);
            v.push_back(val);
            push_heap(v.begin(), v.end());
        } else {
            printf("%d\n", v.front());
            pop_heap(v.begin(), v.end());
            v.pop_back();
        }
    }
    return 0;
}
