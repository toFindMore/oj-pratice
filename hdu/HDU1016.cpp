//
// Created by 周健 on 2020-01-16.
//
#include <stdio.h>
#include <string.h>

const int SIZE = 21;

int visit[SIZE];

int result[SIZE];

int n;

// relation[i][j] == 1 表示数i与数j互质
int primeRegister[2 * SIZE];

bool isPrime(int a) {
    for (int i = 2; i <= a - 1; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

void init() {
    for (int i = 2; i < 2 * SIZE; i++) {
        if (isPrime(i)) {
            primeRegister[i] = 1;
        }
    }
}

// t作为第cnt个数
void dfs(int t, int cnt) {
    // 结束条件
    result[cnt] = t;
    if (cnt == n && primeRegister[1 + result[n]]) {
        printf("%d", result[1]);
        for (int i = 2; i <= n; i++) {
            printf(" %d", result[i]);
        }
        printf("\n");
        return;
    }
    visit[t] = 1;
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        // 如果两者和互质
        if (primeRegister[t + i]) {
            dfs(i, cnt + 1);
        }
    }
    visit[t] = 0;
}

int main() {
    int caseSeq = 0;
    init();
    while (scanf("%d", &n) != EOF) {
        memset(visit, 0, sizeof(visit));
        printf("Case %d:\n", ++caseSeq);
        dfs(1, 1);
        printf("\n");
    }
    return 0;
}