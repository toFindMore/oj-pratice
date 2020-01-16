//
// Created by 周健 on 2020-01-16.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

int num[27][6];

void init() {
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= 5; j++) {
            num[i][j] = (int) pow(i, j);
        }
    }
}

bool flag = true;

inline void print(int i, int j, int k, int t, int m) {
    printf("%c%c%c%c%c\n", i + 'A' - 1, j + 'A' - 1, k + 'A' - 1, t + 'A' - 1, m + 'A' - 1);
    flag = false;
}

int n, cnt;

void cal(int sortedAlpha[]) {
    int sum = 0;
    for (int i = cnt; i >= 0; i--) {
        sum += num[sortedAlpha[i]][1];
        for (int j = cnt; j >= 0; j--) {
            if (j == i) continue;
            sum -= num[sortedAlpha[j]][2];
            for (int k = cnt; k >= 0; k--) {
                if (k == i || k == j) continue;
                sum += num[sortedAlpha[k]][3];
                for (int t = cnt; t >= 0; t--) {
                    if (t == i || t == j || t == k) continue;
                    sum -= num[sortedAlpha[t]][4];
                    for (int c = cnt; c >= 0; c--) {
                        if (c == i || c == j || c == k || c == t) continue;
                        sum += num[sortedAlpha[c]][5];
                        if (sum == n) {
                            print(sortedAlpha[i], sortedAlpha[j], sortedAlpha[k], sortedAlpha[t], sortedAlpha[c]);
                            return;
                        }
                        sum -= num[sortedAlpha[c]][5];
                    }
                    sum += num[sortedAlpha[t]][4];
                }
                sum -= num[sortedAlpha[k]][3];
            }
            sum += num[sortedAlpha[j]][2];
        }
        sum -= num[sortedAlpha[i]][1];
    }
}

int main() {
    char str[13];
    int alpha[26];
    int sortedAlpha[26];
    init();
    while (scanf("%d %s", &n, str) && !(n == 0 && strcmp(str, "END") == 0)) {
        memset(alpha, 0, sizeof(alpha));
        flag = true;
        cnt = -1;
        // 处理str字串
        for (int i = 0; str[i] != '\0'; i++) {
            alpha[str[i] - 'A'] = 1;
        }
        // 存储排序好的字串
        for (int i = 0; i < 26; i++) {
            if (alpha[i]) {
                sortedAlpha[++cnt] = i + 1;
            }
        }
        cal(sortedAlpha);
        if (flag) {
            printf("no solution\n");
        }
    }
    return 0;
}