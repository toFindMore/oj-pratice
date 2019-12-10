//
// Created by 周健 on 2019-09-12.
//

#include <cstdio>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        printf("%d\n", n * m / gcd(n, m));
    }
    return 0;
}