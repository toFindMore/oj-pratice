//
// Created by 周健 on 2020-01-02.
//
#include <stdio.h>
#include <cstring>

const int SIZE = 105;

struct Cost {
    int bug;
    int brain;
} cost[SIZE];

// 注意这边edge要开2倍大小，因为是双向边
struct Node {
    int to;
    int next;
} edge[SIZE * 2];

int head[SIZE];

int tot = 0;

int dp[SIZE][SIZE];

int visit[SIZE];

int n, m;

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int ceil(int t) {
    return t % 20 ? (t / 20 + 1) : t / 20;
}

// 链式前向星 存储树结构
inline void add(int from, int to) {
    edge[++tot].next = head[from];
    edge[tot].to = to;
    head[from] = tot;
}

void init() {
    memset(edge, 0, sizeof(edge));
    memset(head, 0, sizeof(head));
    memset(visit, 0, sizeof(visit));
    memset(dp, 0, sizeof(dp));
    tot = 0;
}

void dfs(int now) {
    // 表示访问过该点
    visit[now] = 1;
    // 一个房间打怪需要的士兵数目
    int tmp = ceil(cost[now].bug);
    // 如果拥有的士兵不够打，则获取不到经验
    for (int i = m; i >= tmp; i--) {
        dp[now][i] = cost[now].brain;
    }
    for (int i = head[now]; i; i = edge[i].next) {
        int to = edge[i].to;
        if (visit[to]) continue;
        dfs(to);
        for (int j = m; j >= tmp; j--) {
            for (int k = 1; k <= j - tmp; k++) {
                // j - k >= tmp
                // j >= tmp
                dp[now][j] = max(dp[now][j], dp[to][k] + dp[now][j - k]);
            }
        }
    }
}

int main() {

    while (scanf("%d%d", &n, &m) && !(n == -1 && m == -1)) {
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &cost[i].bug, &cost[i].brain);
        }
        for (int i = 0; i < n - 1; i++) {
            int n1, n2;
            scanf("%d%d", &n1, &n2);
            add(n1, n2);
            add(n2, n1);
        }
        if (m == 0) {
            printf("0\n");
            continue;
        }
        dfs(1);
        printf("%d\n", dp[1][m]);
    }
    return 0;
}