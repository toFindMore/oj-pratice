//
// https://baike.baidu.com/item/%E6%95%B4%E6%95%B0%E5%88%92%E5%88%86/16472351?fr=aladdin
// Created by 周健 on 2020-02-02.
//
#include <stdio.h>

int partition(int n, int m) {
    if (n == 1 || m == 1) return 1;
    if (n == m) return 1 + partition(n, n - 1);
    if (n < m) return partition(n, n);
    // n > m 含有m和不含有m两种情况
    return partition(n - m, m) + partition(n, m - 1);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", partition(n, n));
    }
    return 0;
}








