//
// https://baike.baidu.com/item/%E6%95%B4%E6%95%B0%E5%88%92%E5%88%86/16472351?fr=aladdin
// Created by 周健 on 2020-02-02.
//
#include <stdio.h>
#include <string.h>

const int MAX = 121;

int map[MAX][MAX];

void init() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            map[i][j] = -1;
        }
    }
}

int partition(int n, int m) {
    if (n == 1 || m == 1) return 1;
    if (map[n][m] != -1) {
        return map[n][m];
    }
    if (n == m) {
        map[n][n - 1] = partition(n, n - 1);
        return 1 + map[n][n - 1];
    }
    if (n < m) {
        map[n][n] = partition(n, n);
        return map[n][n];
    }
    // n > m 含有m和不含有m两种情况
    map[n - m][m] = partition(n - m, m);
    map[n][m - 1] = partition(n, m - 1);
    return map[n - m][m] + map[n][m - 1];
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        init();
        printf("%d\n", partition(n, n));
    }
    return 0;
}