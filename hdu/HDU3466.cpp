//
// Created by 周健 on 2019-08-10.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_N = 5005;
const int SIZE = 505;

struct ProduceInfo {
    int p, q, v;
};

bool cmp(ProduceInfo p1, ProduceInfo p2) {
    int v1 = p1.q - p1.p;
    int v2 = p2.q - p2.p;
    if (v1 <= v2) return true;
    return false;
}

int main() {
    int n, m;
    int dp[MAX_N];
    ProduceInfo p[SIZE];
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &p[i].p, &p[i].q, &p[i].v);
        }
        sort(p + 1, p + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= p[i].p; j--) {
                if(j >= p[i].q) {
                    dp[j] = max(dp[j], dp[j - p[i].p] + p[i].v);
                }
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
