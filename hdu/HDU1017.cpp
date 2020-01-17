//
// Created by 周健 on 2020-01-16.
//
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int caseNum = 0;
        int n, m;
        while (scanf("%d%d", &n, &m), n != 0 || m != 0) {
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if ((i * i + j * j + m) % (i * j) == 0) {
                        ++cnt;
                    }
                }
            }
            printf("Case %d: %d\n", ++caseNum, cnt);
        }
        if (N) {
            printf("\n");
        }
    }
    return 0;
}
