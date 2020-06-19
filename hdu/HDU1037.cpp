//
// Created by 周健 on 2020-06-19.
//
#include <stdio.h>

int main() {
    int data[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &data[i]);
    }
    int res = -9999;
    for (int i = 0; i < 3; i++) {
        if (data[i] < 168) {
            res = (res > data[i]) ? res : data[i];
        }
    }
    if (res != -9999) {
        printf("CRASH %d\n", res);
    } else {
        printf("NO CRASH\n", res);
    }
    return 0;
}