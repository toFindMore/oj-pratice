//
// Created by 周健 on 2020-05-22.
//
#include <stdio.h>

int main() {
    int n;
    int arr[1005];
    int pre[1005];
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int round = 0;
        while (true) {
            // 次数加1
            ++round;

            // 传递糖
            for (int i = 0; i < n - 1; i++) {
                arr[i] /= 2;
                pre[i + 1] = arr[i];
            }
            arr[n-1] /= 2;
            pre[0] = arr[n - 1];

            // 老师给单数的学生糖
            bool isEqual = true;
            for (int i = 0; i < n; i++) {
                arr[i] += pre[i];
                if (arr[i] & 1) {
                    arr[i] += 1;
                }
                if (arr[i] != arr[0]) {
                    isEqual = false;
                }
            }

            // 退出
            if (isEqual) {
                break;
            }
        }
        printf("%d %d\n", round, arr[0]);

    }
    return 0;
}