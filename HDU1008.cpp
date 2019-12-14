//
// Created by 周健 on 2019-12-14.
//
#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int sum = 5 * n;
        int step = 0;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            if (temp > step) {
                sum += ((temp - step) * 6);
            } else if (temp < step) {
                sum += ((step - temp) * 4);
            }
            step = temp;
        }
        printf("%d\n", sum);
    }
    return 0;
}