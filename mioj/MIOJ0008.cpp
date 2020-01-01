//
// Created by 周健 on 2019-08-30.
//
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 1001;

int ar[SIZE];

int lowbit(int x) {
    return x & (-x);
}

void add(int i, int v) {
    for (; i < SIZE; i += lowbit(i)) {
        ar[i] += v;
    }
}

int sum1(int i) {
    int s = 0;
    for (; i > 0; i -= lowbit(i)) {
        s += ar[i];
    }
    return s;
}

int main() {
    // please write your code here
    int d;
    char c;
    int sum = 0;
    while (cin >> d) {
        cin >> c;
        add(d, 1);
        //cout << d << endl;
        sum += (sum1(SIZE) - sum1(d));
        if (c == '\n') break;
    }
    printf("%d\n", sum);
    return 0;
}