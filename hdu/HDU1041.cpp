//
// Created by 周健 on 2020-07-02.
//
#include <stdio.h>
#include <string.h>

char dp[1005][400];
char g[1005][400];

void add(char *num1, char *num2, char *res) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 > len2) {
        char *tmp = num1;
        num1 = num2;
        num2 = tmp;
        len1 = len2;
        len2 = strlen(num2);
    }
    int step = 0;
    int cnt = -1;
    for (int i = 0; i < len1; i++) {
        int tmp = (num1[i] - '0') + (num2[i] - '0') + step;
        if (tmp >= 10) {
            step = 1;
            tmp -= 10;
        } else {
            step = 0;
        }
        res[++cnt] = tmp + '0';
    }
    for (int i = len1; i < len2; i++) {
        int tmp = (num2[i] - '0') + step;
        if (tmp >= 10) {
            step = 1;
            tmp -= 10;
        } else {
            step = 0;
        }
        res[++cnt] = tmp + '0';
    }
    if (step == 1) {
        res[++cnt] = '1';
    }
    res[++cnt] = '\0';
}

void init() {
    g[0][0] = '1';
    g[0][1] = '\0';
    for (int i = 0; i < 999; i++) {
        add(g[i], g[i], g[i + 1]);
    }
    dp[1][0] = '0';
    dp[1][1] = '\0';
    dp[2][0] = '1';
    dp[2][1] = '\0';
    for (int i = 3; i <= 1000; i++) {
        add(dp[i - 2], g[i - 3], dp[i]);
    }
}

int main() {
    // 初始化
    init();
    // 计算
    int num;
    while (scanf("%d", &num) != EOF) {
        for (int i = strlen(dp[num])-1; i >= 0; i--) {
            printf("%c", dp[num][i]);
        }
        printf("\n");
    }
    return 0;
}