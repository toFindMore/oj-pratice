//
// Created by 周健 on 2020-07-01.
//
#include <stdio.h>
#include <algorithm>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int cnt, num[1005];
        scanf("%d", &cnt);
        for (int i = 0; i < cnt; i++) {
            scanf("%d", &num[i]);
        }
        std::sort(num, num + cnt);
        for (int i = 0; i < cnt; i++) {
            printf("%d", num[i]);
            if (i != cnt - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}