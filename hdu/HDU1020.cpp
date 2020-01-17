//
// Created by 周健 on 2020-01-17.
//
#include <stdio.h>

int main() {
    int T;
    char str[10005];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        // 计数器
        int cnt = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            ++cnt;
            if (str[i + 1] == '\0' || str[i + 1] != str[i]) {
                if (cnt != 1) {
                    printf("%d", cnt);
                }
                printf("%c", str[i]);
                cnt = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
