//
// Created by 11119600 on 2020/9/3.
//
#include <stdio.h>

const int SIZE = 30005;

int link[SIZE];

int find(int x) {
    if (x == link[x]) {
        return x;
    }
    return link[x] = find(link[x]);
}

void merge(int x1, int x2) {
    int root1 = find(x1);
    int root2 = find(x2);
    if (root1 != root2) {
        link[root1] = root2;
    }
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) && !(n == 0 && m == 0)) {
        for (int i = 0; i < SIZE; i++) {
            link[i] = i;
        }
        for (int j = 0; j < m; j++) {
            int k;
            scanf("%d", &k);
            if (k == 0) continue;
            int pre;
            scanf("%d", &pre);
            for (int i = 1; i < k; i++) {
                int tmp;
                scanf("%d", &tmp);
                merge(pre, tmp);
            }
        }

        int root0 = find(0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == root0) {
                ++res;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}