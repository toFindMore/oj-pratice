//
// 莫队算法
// Created by 周健 on 3/20/21.
//
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 4;
int a[maxn];
int unit;

struct Q {
    int L, R, idx;
} q[maxn];

int CMP(Q q1, Q q2) {
    if (q1.L / unit == q2.L / unit) return q1.R < q2.R;
    return q1.L / unit < q2.L / unit;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    unit = sqrt(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &q[i].L, &q[i].R);
        q[i].idx = i;
    }
    sort(q, q + m, CMP);
    int l = 1, r = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        // 四种操作
        while (l < q[i].L) {

        }
        while (l > q[i].L) {

        }
        while (r < q[i].R) {

        }
        while (r > q[i].R) {

        }
    }
    return 0;
}
