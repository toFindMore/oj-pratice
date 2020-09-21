//
// Created by 周健 on 2020-09-04.
//
#include <stdio.h>

void transfer(int x, int *num) {
    int cnt = -1;
    while (x) {
        num[++cnt] = x % 2;
        x /= 2;
    }
    while (cnt <= 30) {
        num[++cnt] = 0;
    }
}

int minFlips(int a, int b, int c) {
    int aArr[32];
    int bArr[32];
    int cArr[32];
    transfer(a, aArr);
    transfer(b, bArr);
    transfer(c, cArr);
    int res = 0;
    for (int i = 0; i < 32; i++) {
        if (cArr[i] == 1) {
            if (aArr[i] == 0 && bArr[i] == 0) ++res;
        } else {
            if (aArr[i] == 1) ++res;
            if (bArr[i] == 1) ++res;
        }
    }
    return res;
}

int main() {
    printf("%d",minFlips(4,2,7));
    return 0;
}