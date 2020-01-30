//
// Created by 周健 on 2020-01-28.
//
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

struct Node {
    int index, v;
} node[MAXN];

int c[MAXN];

int n;

int cmp(Node n1, Node n2) {
    return n1.index < n2.index;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int lowbit(int x) {
    return x & (-x);
}

int query(int x) {
    int res = 0;
    while (x) {
        res = max(c[x], res);
        x -= lowbit(x);
    }
    return res;
}

int modifier(int x, int v) {
    while (x <= n) {
        c[x] = max(c[x], v);
        x += lowbit(x);
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        // init
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &node[i].index, &node[i].v);
        }
        sort(node + 1, node + n + 1, cmp);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = query(node[i].v - 1) + 1;
            res = max(res, tmp);
            modifier(node[i].v, tmp);
        }
        printf("My king, at most %d road can be built.\n\n", res);
    }
    return 0;
}