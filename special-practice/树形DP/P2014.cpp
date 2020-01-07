//
// Created by 周健 on 2020-01-06.
//
#include <stdio.h>

// 不能为0
int tot;

// 利用链式前向星进行数据存储
int head[301];

int max(int a, int b) {
    return a > b ? a : b;
}

struct Node {
    int to;
    int next;
} edge[601];

int dp[301][301];

int n, m;

void add(int from, int to) {
    edge[++tot].next = head[from];
    edge[tot].to = to;
    head[from] = tot;
}

void dfs(int now) {
    for (int k = head[now]; k; k = edge[k].next) {
        int to = edge[k].to;
        dfs(to);
        // 这里包括虚拟节点
        for (int i = m + 1; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                dp[now][i] = max(dp[now][i], dp[to][j] + dp[now][i - j]);
                // 以下情况会导致覆盖 dp[now][i]中的i必须要比 dp[now][i - j] 要小
                // dp[now][i] = max(dp[now][i], dp[now][j] + dp[to][i - j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int v, value;
        scanf("%d%d", &v, &value);
        dp[i][1] = value;
        add(v, i);
    }
    dfs(0);
    // 共有m+1个，因为虚拟节点也算一个
    printf("%d\n", dp[0][m + 1]);
    return 0;
}
