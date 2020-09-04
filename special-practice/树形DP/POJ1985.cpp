//
// Created by 周健 on 2020-01-07.
//
#include <stdio.h>

const int SIZE = 100005;

int head[SIZE];

// 包含该点的最大距离 (可能是中间节点)
struct DP {
    int num1;
    int num2;
} dp[SIZE];

// 包含该点的最大距离（是端点）
int dp_edge[SIZE];

int visit[SIZE];

struct Node {
    int weight;
    int to;
    int next;
} e[SIZE];

int tot;

int max(int a, int b) {
    return a > b ? a : b;
}

void add(int from, int to, int weight) {
    e[++tot].to = to;
    e[tot].weight = weight;
    e[tot].next = head[from];
    head[from] = tot;
}

void dfs(int now) {
    if (visit[now]) {
        return;
    }
    visit[now] = true;
    int tmp;
    for (int i = head[now]; i; i = e[i].next) {
        int to = e[i].to;
        if (visit[to]) {
            continue;
        }
        dfs(to);
        int num = dp_edge[to] + e[i].weight;
        dp_edge[now] = max(dp_edge[now], num);
        if (num > dp[now].num1 || num > dp[now].num2) {
            if (dp[now].num1 < dp[now].num2) {
                dp[now].num1 = num;
            } else {
                dp[now].num2 = num;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        char c;
        int from, to, weight;
        scanf("%d%d%d %c", &from, &to, &weight, &c);
        add(from, to, weight);
        add(to, from, weight);
    }
    int res = -1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i].num1 + dp[i].num2);
    }
    printf("%d\n", res);
    return 0;
}