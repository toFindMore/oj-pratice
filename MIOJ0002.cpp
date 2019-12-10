//
// Created by 周健 on 2019-08-18.
//
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // please write your code here
    short p = 0;
    int d;
    while (scanf("%d",&d)!=EOF) {
        p = (p ^ d);
    }
    printf("%d\n", p);
    return 0;
}
