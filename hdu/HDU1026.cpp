//
// Created by 周健 on 2020-01-31.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utility>

const int INF = 0x3ffffff;

const int MAXN = 105;

char rooms[MAXN][MAXN];

int visit[MAXN][MAXN];

int n, m, minValue;

int direction[4][2] = {{0,  1},
                       {1,  0},
                       {-1, 0},
                       {0,  -1}};

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = INF;
        }
    }
    minValue = INF;
}

struct Path {
    std::pair<int, int> path[MAXN];
    int length;
} resPath;

void copyPath(std::pair<int, int> path[], int cnt) {
    for (int i = 0; i <= cnt; i++) {
        resPath.path[i].first = path[i].first;
        resPath.path[i].second = path[i].second;
    }
    resPath.length = cnt;
}

void dfs(int x, int y, int cost, std::pair<int, int> path[], int cnt) {
    // 越界
    if (x < 0 || x > n - 1 || y < 0 || y > m - 1) return;
    if (rooms[x][y] == 'X') return;
    if (rooms[x][y] != '.') cost += rooms[x][y] - '0';
    // 剪枝优化 表示有更加优化的走法已经走过了 这里再这样走就没有意义了
    if (visit[x][y] <= cost) return;
    visit[x][y] = cost;
    // 加路径
    path[cnt].first = x;
    path[cnt].second = y;
    // 到达终点
    if (x == n - 1 && y == m - 1) {
        if (minValue <= cost) return;
        minValue = cost;
        // 更新路径
        copyPath(path, cnt);
        return;
    }
    // 往周边走
    for (int i = 0; i < 4; i++) {
        dfs(x + direction[i][0], y + direction[i][1], cost + 1, path, cnt + 1);
    }
}


int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (int i = 0; i < n; i++) {
            getchar();
            for (int j = 0; j < m; j++) {
                scanf("%c", &rooms[i][j]);
            }
        }
        std::pair<int, int> path[MAXN];
        dfs(0, 0, 0, path, 0);
        if (visit[n - 1][m - 1] == INF) {
            printf("God please help our poor hero.\nFINISH\n");
            continue;
        }
        printf("It takes %d seconds to reach the target position, let me show you the way.\n", minValue);
        int second = 0;
        for (int i = 0; i < resPath.length; i++) {
            int x1 = resPath.path[i].first;
            int y1 = resPath.path[i].second;
            int x2 = resPath.path[i + 1].first;
            int y2 = resPath.path[i + 1].second;
            printf("%ds:(%d,%d)->(%d,%d)\n", ++second, x1, y1, x2, y2);
            if (rooms[x2][y2] != '.') {
                for (int j = 0; j < rooms[x2][y2] - '0'; j++) {
                    printf("%ds:FIGHT AT (%d,%d)\n", ++second, x2, y2);
                }
            }
        }
        printf("FINISH\n");
    }
    return 0;
}
// MODEL
/*
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX.
5 6
.XX.1.
..X.2.
2...X.
...XX.
XXXXX1
5 6
.XX...
..XX1.
2...X.
...XX.
XXXXX.
 */
// ANS
/*
It takes 13 seconds to reach the target position, let me show you the way.
1s:(0,0)->(1,0)
2s:(1,0)->(1,1)
3s:(1,1)->(2,1)
4s:(2,1)->(2,2)
5s:(2,2)->(2,3)
6s:(2,3)->(1,3)
7s:(1,3)->(1,4)
8s:FIGHT AT (1,4)
9s:FIGHT AT (1,4)
10s:(1,4)->(1,5)
11s:(1,5)->(2,5)
12s:(2,5)->(3,5)
13s:(3,5)->(4,5)
FINISH
It takes 14 seconds to reach the target position, let me show you the way.
1s:(0,0)->(1,0)
2s:(1,0)->(1,1)
3s:(1,1)->(2,1)
4s:(2,1)->(2,2)
5s:(2,2)->(2,3)
6s:(2,3)->(1,3)
7s:(1,3)->(1,4)
8s:FIGHT AT (1,4)
9s:FIGHT AT (1,4)
10s:(1,4)->(1,5)
11s:(1,5)->(2,5)
12s:(2,5)->(3,5)
13s:(3,5)->(4,5)
14s:FIGHT AT (4,5)
FINISH
God please help our poor hero.
FINISH
 */