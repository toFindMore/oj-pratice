//
// Created by 周健 on 2019-12-10.
//
#include <stdio.h>

int main() {
    int T;
    int a[100005], dp[100005];
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        dp[0] = a[0];
        int max = dp[0];
        int left = 0, right = 0, sg = 0;
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j - 1] >= 0 ? dp[j - 1] + a[j] : a[j];
            if (dp[j - 1] < 0) {
                sg = j;
            }
            if (max < dp[j]) {
                max = dp[j];
                left = sg;
                right = j;
            }
        }
        printf("Case %d:\n", i);
        printf("%d %d %d\n", max, left + 1, right + 1);
        if (i != T) {
            printf("\n");
        }
    }
    return 0;
}

