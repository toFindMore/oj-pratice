//
// Created by 周健 on 2020-01-02.
// https://www.luogu.com.cn/problem/P2015

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int value;
    int left;
    int right;

    Node() {
        value = 0;
        left = -1;
        right = -1;
    }
};

const int SIZE = 105;

Node node[SIZE];

// dp[i][j] 表示序号i的树有j个枝桠的最大值
int dp[SIZE][SIZE];

int dfs(int pos, int cnt) {
    if (pos == 0 || cnt == 0) {
        return 0;
    }
    if (node[pos].left == -1 && node[pos].right == -1) {
        return node[pos].value;
    }
    if (dp[pos][cnt] != -1) {
        return dp[pos][cnt];
    }
    // 这边需要减去本身
    for (int i = 0; i < cnt; i++) {
        dp[pos][cnt] = max(dp[pos][cnt], dfs(node[pos].left, i) + dfs(node[pos].right, cnt - i - 1) + node[pos].value);
    }
    return dp[pos][cnt];
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    // 初始化
    fill(dp[0], dp[0] + SIZE * SIZE, -1);
    for (int i = 0; i < n - 1; i++) {
        int from, to, value;
        scanf("%d%d%d", &from, &to, &value);
        if (node[from].left == -1) {
            node[from].left = to;
        } else {
            node[from].right = to;
        }
        node[to].value = value;
    }

    printf("%d\n", dfs(1, q + 1));
    return 0;
}

/**

Example:
5 2
1 3 1
1 4 10
3 2 20
3 5 20

Answer:
21
**/