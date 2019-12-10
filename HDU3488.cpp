//
// Created by 周健 on 2019-08-10.
//
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, k, ans;
int a[45];

void dfs(int t, int i, int x) {
    ans = max(ans, x);
    if (i > k) return;
    // 这个物品需要取
    if (t + 1 <= n && x + a[i] <= m)
        dfs(t + 1, i + 1, x + a[i]);
    dfs(t, i + 1, x);
}

bool cmp(int a, int b) { return a > b; }

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        scanf("%d", &k);
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= k; i++)scanf("%d", &a[i]);
        sort(a + 1, a + 1 + k, cmp);
        int sum = 0;
        for (int i = 1; i <= n; i++)sum += a[i];
        // 剪枝
        if (m >= sum) {
            printf("%d\n", sum);
            continue;
        }
        ans = 0;
        dfs(0, 1, 0);   ///0---n,1---数组脚标,0---ans;
        printf("%d\n", ans);
    }
    return 0;
}
