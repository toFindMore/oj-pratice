//
// Created by 周健 on 2019-08-31.
//
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

const int N = 100005;
int a[N], b[N];
int reg[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int n, int x) {
    for (; x < N; x += lowbit(x)) {
        reg[x] += n;
    }
}

int getSum(int x) {
    int sum = 0;
    for (; x > 0; x -= lowbit(x)) {
        sum += reg[x];
    }
    return sum;
}

int main() {
    int n, x, y;
    int sum1, sum2;
    while (scanf("%d%d%d", &n, &x, &y) != EOF) {
        memset(reg, 0, sizeof(reg));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        //cout << "get";
        /**
         * 离散化
         * 1.排序
         * 2.去重复，算出个数
         * 3.哈希映射
         */
        unordered_map<int, int> HASH;
        sort(a, a + n);
        int size = unique(a, a + n) - a;
        for (int i = 1; i <= size; i++) {
            HASH[a[i-1]] = i;
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            add(1, HASH[b[i]]);
            sum1 = getSum(HASH[b[i]]);
            sum2 = getSum(N-1);
            sum += (sum2 - sum1);
        }
        int price = x > y ? y : x;
        printf("%lld\n", price * sum);
    }
    return 0;
}