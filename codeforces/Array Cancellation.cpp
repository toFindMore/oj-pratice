//
// Created by 周健 on 2020-09-06.
//
#include <stdio.h>

using namespace std;

int main() {
    int caseNum, n;
    int a[100005];
    scanf("%d", &caseNum);
    while (caseNum--) {
        scanf("%d", &n);
        long long tmp = 0;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > 0) {
                tmp += a[i];
            } else {
                if (-a[i] > tmp) {
                    res += (-a[i] - tmp);
                    tmp = 0;
                } else {
                    tmp = tmp + a[i];
                }
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
