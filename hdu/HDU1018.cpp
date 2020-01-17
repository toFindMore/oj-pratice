//
// Created by 周健 on 2020-01-17.
//
#include <stdio.h>
#include<cstdio>
#include<cmath>

using namespace std;

/*
m! = a * 10^b , 1 <= a <10 <=> log10(n!) = log10(a) + b
<=> result: b + 1 = log10(1) + log10(2) + ... + log10(n) - log10(a) + 1
<=> result: b + 1 <= log10(1) + log10(2) + ... + log10(n) + 1
*/
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d,", &n);
        double sum = 1.0;
        for (int i = 2; i <= n; i++) {
            sum += log10(i);
        }
        printf("%d\n", (int) floor(sum));
    }
    return 0;
}
