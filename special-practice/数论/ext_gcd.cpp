//
// Created by 周健 on 2020-01-20.
//
#include <stdio.h>

int ext_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = ext_gcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int main() {

    return 0;
}
