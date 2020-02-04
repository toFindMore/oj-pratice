//
// Created by 周健 on 2020-02-03.
//
#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int time = 0;
        int res;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (time == 0) {
                res = tmp;
                ++time;
                continue;
            }
            if (res == tmp) {
                ++time;
                continue;
            }
            --time;
        }
        printf("%d\n", res);
    }
    return 0;
}
