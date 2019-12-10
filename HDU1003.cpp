//
// Created by 周健 on 2019-12-10.
//
#include <stdio.h>

int main() {
    int T;
    int a[100005];
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }


        printf("Case %d:\n", i);

    }
    return 0;
}