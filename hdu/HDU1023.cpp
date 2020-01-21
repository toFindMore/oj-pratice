//
// Created by 周健 on 2020-01-20.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

const int SIZE = 205;

const int STR_LEN = 100;

char C[SIZE][SIZE][STR_LEN];

/**
 * 字符串反转
 *
 * @param c
 */
void reverse(char *c) {
    int len = strlen(c);
    for (int i = 0; i < len / 2; i++) {
        char tmp = c[i];
        c[i] = c[len - i - 1];
        c[len - i - 1] = tmp;
    }
}

/**
 * 大数加法
 *
 * @param num1 加数1
 * @param num2 加数2
 * @param res  和
 */
void add(char *num1, char *num2, char *res) {
    int step = 0;
    int i, j;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int cnt = -1;
    for (i = len1 - 1, j = len2 - 1;;) {
        char c1 = num1[i], c2 = num2[j];
        if (i == -1 && j == -1) break;
        if (i == -1) c1 = '0'; else --i;
        if (j == -1) c2 = '0'; else --j;
        int num = c1 - '0' + c2 - '0' + step;
        if (num >= 10) {
            res[++cnt] = num - 10 + '0';
            step = 1;
        } else {
            res[++cnt] = num + '0';
            step = 0;
        }
    }
    if (step == 1) {
        res[++cnt] = '1';
    }
    res[++cnt] = '\0';
    reverse(res);
}

/**
 * 大数减法（版1：除数是合理范围的数）
 *
 * @param num 被除数
 * @param n    除数
 */
void *div(char *num, int n) {
    int p = 0;
    int len = strlen(num);
    // 余数
    int tmp = 0;
    // 去除前导0
    bool flag = true;
    for (; p < len;) {
        tmp *= 10;
        tmp += num[p++] - '0';
        if (tmp / n != 0) flag = false;
        if (!flag) printf("%d", tmp / n);
        tmp = tmp % n;
    }
}

// C(n,m) = C(n-1,m) + C(n-1,m-1)
void init() {
    for (int i = 0; i < SIZE; i++) {
        strcpy(C[i][0], "1");
    }
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            add(C[i - 1][j], C[i - 1][j - 1], C[i][j]);
        }
    }
}

// Catalan
// h(n) = C(2n,n) / (n+1)
// h(n) = h(n-1) * (4*n-2)/(n+1)
// h(n) = h(0) * h(n-1) + h(1) * h(n-2) + ... + h(n-1)h(0) , 其中 n>=2
int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        div(C[2 * n][n], n + 1);
        printf("\n");
    }
    return 0;
}

