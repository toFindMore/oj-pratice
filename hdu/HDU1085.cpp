//
// 母函数
// Created by 周健 on 2020-02-03.
//
#include <stdio.h>
#include <string.h>

const int MAX = 10000;

bool visit[MAX];
int c[MAX];
int c_copy[MAX];

int main() {
    int num[3];
    int size = 3;
    int value[3] = {1, 2, 5};
    while (scanf("%d%d%d", &num[0], &num[1], &num[2]) != EOF && !(num[0] == 0 && num[1] == 0 && num[2] == 0)) {
        memset(visit, false, sizeof(visit));
        memset(c, 0, sizeof(c));
        int pre = 0;
        for (int i = 0; i < size; i++) {
            // c[i]与num[i]相加
            int cnt = -1;
            for (int j = 0; j <= value[i] * num[i]; j += value[i]) {
                for (int k = 0; k <= pre; k++) {
                    int index = c[k] + j;
                    if (visit[index]) {
                        continue;
                    }
                    visit[index] = true;
                    c_copy[++cnt] = index;
                }
            }
            // copy to c
            for (int j = 0; j <= cnt; j++) {
                c[j] = c_copy[j];
            }
            pre = cnt;
        }
        for (int i = 0; i < MAX; i++) {
            if (!visit[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
