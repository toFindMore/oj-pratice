//
// Created by 周健 on 2020-01-21.
//
#include <stdio.h>

const int INF = -0x3fffff;

int main() {
    int n, m, tmp;
    while (scanf("%d%d", &n, &m) != EOF) {
        long long res = INF;
        long long dp = INF;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &tmp);
            dp = dp < 0 ? tmp : dp + tmp;
            res = res > dp ? res : dp;
            printf("dp = %d\n", dp);
        }
        printf("%lld\n", res);
    }
    return 0;
}
// 2 6 -1 4 -2 3 -2 3