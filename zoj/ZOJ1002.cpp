//
// Created by 周健 on 2020-01-31.
//
#include <stdio.h>

const int MAXN = 4;

char map[MAXN][MAXN];

int n;

bool isQualified(int x, int y) {
    if (map[x][y] == 'X') return false;
    // 上
    for (int i = x - 1; i >= 0; --i) {
        if (map[i][y] == 'X') break;
        if (map[i][y] == 'P') return false;
    }
    // 下
    for (int i = x + 1; i <= n - 1; ++i) {
        if (map[i][y] == 'X') break;
        if (map[i][y] == 'P') return false;
    }
    // 左
    for (int i = y - 1; i >= 0; --i) {
        if (map[x][i] == 'X') break;
        if (map[x][i] == 'P') return false;
    }
    // 右
    for (int i = y + 1; i <= n - 1; ++i) {
        if (map[x][i] == 'X') break;
        if (map[x][i] == 'P') return false;
    }
    return true;
}

int res;

void cal() {
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 'P') {
                ++num;
            }
        }
    }
    res = res > num ? res : num;
}

void dfs(int k) {
    if (k == n * n) {
        return;
    }
    int x = k / n;
    int y = k % n;
    if (isQualified(x, y)) {
        map[x][y] = 'P';
        // 放
        cal();
        // 深搜
        dfs(k + 1);
        map[x][y] = '.';
    }
    // 不放
    cal();
    dfs(k + 1);
}

int main() {
    while (scanf("%d", &n), n != 0) {
        res = -1;
        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < n; j++) {
                scanf("%c", &map[i][j]);
            }
        }
        dfs(0);
        printf("%d\n", res);
    }
    return 0;
}
