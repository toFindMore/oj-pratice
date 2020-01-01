//
// Created by 周健 on 2019-12-09.
//
#include <stdio.h>

int main() {
    long long n, res;
    while (scanf("%lld", &n) != EOF) {
        if (n % 2 == 0) {
            res = n / 2 * (n + 1);
        } else {
            res = (n + 1) / 2 * n;
        }
        printf("%lld\n\n", res);
    }
    return 0;
}
