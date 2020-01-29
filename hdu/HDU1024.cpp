//
// Created by 周健 on 2020-01-21.
//
#include <stdio.h>
#include <cstring>

const int INF = 0x3fffffff;

const int SIZE = 1000005;

int a[SIZE];

int dp[SIZE];

int dp_k[SIZE];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        // init
        memset(dp, 0, sizeof(dp));
        memset(dp_k, 0, sizeof(dp_k));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int tmp;
        // dp[i][j] = max(dp[i][j-1]+a[j], max(dp[i-1][k]+a[j]) ) (其中 i-1 <= k <= j-1)
        // dp_k[j] = max(dp[i-1][i-1], dp[i-1][i], ..., dp[i-1][j-1]);
        for (int i = 1; i <= m; i++) {
            // 当分为i份时的最大值
            tmp = -INF;
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j - 1], dp_k[j - 1]) + a[j];
                // 更新相关数据，i+1时可以使用
                dp_k[j - 1] = tmp;
                // 更新最大值
                tmp = max(dp[j], tmp);
            }
        }
        printf("%d\n", tmp);
    }
    return 0;
}
/*
1 3 1 2 3
2 6 -1 4 -2 3 -2 3
*/