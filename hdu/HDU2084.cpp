//
// Created by 周健 on 2019-08-05.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAX_N = 105;

int main() {
    int C;
    scanf("%d", &C);
    int arr[MAX_N][MAX_N] = {0};
    int dp[MAX_N][MAX_N] = {0};
    for (int i = 0; i < C; i++) {
        int n;
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < j; k++) {
                scanf("%d", &arr[j][k]);
            }
        }
        dp[1][0] = arr[1][0];
        for (int j = 2; j <= n; j++) {
            for (int k = 0; k < j; k++) {
                if (k == 0) {
                    dp[j][k] = arr[j][k] + dp[j - 1][k];
                } else if (k == j - 1) {
                    dp[j][k] = arr[j][k] + dp[j - 1][k - 1];
                } else {
                    dp[j][k] = arr[j][k] + max(dp[j - 1][k], dp[j - 1][k - 1]);
                }
            }
        }
        int max_n = -1;
        for (int j = 0; j < n; j++) {
            max_n = max_n > dp[n][j] ? max_n : dp[n][j];
        }
        printf("%d\n", max_n);
    }
}
