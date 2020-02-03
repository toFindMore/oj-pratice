//
// Created by 周健 on 2020-02-02.
//
#include <stdio.h>
#include <string.h>

const int MAXN = 10001;

int prime[MAXN];

bool isPrime[MAXN];

void init1() {
    int cnt = -1;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (isPrime[i]) {
            prime[++cnt] = i;
        }
        for (int j = i * 2; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
}

// 优化后的筛法
void init2() {
    int cnt = -1;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (isPrime[i]) {
            prime[++cnt] = i;
        }
        for (int j = 1; j <=cnt && prime[j] * i < MAXN; ++j) {
            isPrime[prime[j] * i] = false;
        }
    }
}

int main() {
    init2();
    for (int i = 0; i < 20; i++) {
        printf("%d\n", prime[i]);
    }
}
