//
// Created by 周健 on 2020-01-20.
//
#include <stdio.h>

// gcd(a, b) = gcd(b, a % b)  b != 0
// gcd(a, b) = gcd(b, a % b) 证明链接：https://www.cnblogs.com/Howe-Young/p/4329362.html
int gcd(int x, int y) {
    // 如果两数中有一个数是0
    if (!x || !y) {
        return x > y ? x : y;
    }
    for (int t; t = x % y, t; x = y, y = t);
    return y;
}

int main() {
    printf("%d\n", gcd(35, 14));
    // expect: 7
    return 0;
}
