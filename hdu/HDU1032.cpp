//
// Created by 周健 on 2020-02-06.
//
#include <stdio.h>
#include <string.h>
#include <map>

std::map<long long, long long> cache;

long long cal(long long i) {
    if (i == 1) {
        return 1;
    }
    // 记录
    if (cache.count(i)) {
        return cache[i];
    }
    // 如果是奇数
    if (i & 1) {
        cache[i] = cal(3 * i + 1) + 1;
        return cache[i];
    } else {
        cache[i] = cal(i >> 1) + 1;
        return cache[i];
    }
}

int main() {
    long long n, m;
    long long s, e;
    while (scanf("%lld%lld", &n, &m) != EOF) {
        s = n < m ? n : m;
        e = n < m ? m : n;
        long long res = 0;
        for (int i = s; i <= e; i++) {
            long long tmp = cal(i);
            res = res > tmp ? res : tmp;
        }
        printf("%lld %lld %lld\n", n, m, res);
    }
    return 0;
}
