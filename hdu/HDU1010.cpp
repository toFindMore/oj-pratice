//
// Created by 周健 on 2019-12-30.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int SIZE = 10;
const int INF = 0x3ffffff;

int n, m, t;
int endI, endJ;
int cnt[SIZE][SIZE];
char maze[SIZE][SIZE];
bool visit[SIZE][SIZE];
bool flag;

void travel(int i, int j, int step) {
    // 不能继续下去的条件
    if (step == -1 || i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 'X' || visit[i][j] || flag) {
        return;
    }
    // 第step步刚好门开
    if (maze[i][j] == 'D' && step == 0) {
        flag = true;
        return;
    }

    // 重要剪枝，否则会超时。x算出的是绝对最近距离
    // x的奇偶性一定与step一致，否则在step步跳不到目标格子
    int x = abs(endI - i) + abs(endJ - j);
    if (x > step || (x & 1) ^ (step & 1)) {
        return;
    }

    visit[i][j] = true;
    travel(i + 1, j, step - 1);
    travel(i - 1, j, step - 1);
    travel(i, j + 1, step - 1);
    travel(i, j - 1, step - 1);
    visit[i][j] = false;
}

int main() {
    int startI, startJ;
    while (scanf("%d%d%d", &n, &m, &t) && n || m || t) {
        fill(visit[0], visit[0] + SIZE * SIZE, false);
        fill(cnt[0], cnt[0] + SIZE * SIZE, INF);
        flag = false;
        startI = -1;
        startJ = -1;
        getchar();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'S') {
                    startI = i;
                    startJ = j;
                } else if (maze[i][j] == 'D') {
                    endI = i;
                    endJ = j;
                }
            }
            getchar();
        }
        travel(startI, startJ, t);
        flag ? printf("YES\n") : printf("NO\n");;
    }
    return 0;
}