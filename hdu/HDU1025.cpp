//
// Created by 周健 on 2020-01-28.
//
#include <stdio.h>
#include <cstring>

int card[16];

void init() {
    for (int i = 1; i <= 13; i++) {
        card[i] = 4;
    }
    card[14] = 2;
}

void print() {
    printf("  A  2  3  4  5  6  7  8  9 10  J  Q  K  King\n");
    for (int i = 1; i <= 14; i++) {
        printf("%3d", card[i]);
    }
    printf("\n");
    card[14] = 2;
}

int main() {
    int T = 1000;
    init();
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            init();
            continue;
        }
        card[n]--;
        print();
    }
    return 0;
}