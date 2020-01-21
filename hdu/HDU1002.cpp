//
// Created by 周健 on 2019-12-09.
//
#include <stdio.h>
#include <string.h>

const int SIZE = 1005;

void reverse(char *c) {
    int len = strlen(c);
    for (int i = 0; i < len / 2; i++) {
        char tmp = c[i];
        c[i] = c[len - i - 1];
        c[len - i - 1] = tmp;
    }
}

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

int main() {
    int T;
    char num1[SIZE], num2[SIZE], res[SIZE];
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        scanf("%s%s", num1, num2);
        printf("Case %d:\n", k);
        add(num1, num2, res);
        printf("%s + %s = %s\n", num1, num2, res);
        if (k != T) {
            printf("\n");
        }
    }
    return 0;
}
