//
// Created by 周健 on 2020-01-17.
//
#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int m = 1;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            m = lcm(m, tmp);
        }
        printf("%d\n", m);
    }
    return 0;
}