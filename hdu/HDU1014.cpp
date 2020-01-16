//
// Created by 周健 on 2020-01-16.
//
#include <stdio.h>

int step, mod;

int seed(int t) {
    return (t + step) % mod;
}

int main() {
    while (scanf("%d%d", &step, &mod) != EOF) {
        int k = seed(0);
        int cnt = 1;
        while (k) {
            k = seed(k);
            ++cnt;
        }
        printf("%10d%10d    ", step, mod);
        if (cnt == mod) {
            printf("Good Choice");
        } else {
            printf("Bad Choice");
        }
        printf("\n\n");
    }
    return 0;
}
