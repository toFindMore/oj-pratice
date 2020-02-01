//
// BFS
// Created by 周健 on 2020-01-31.
//
#include <stdio.h>
#include <string.h>
#include <queue>

const int MAXN = 105;

int n, m;

bool visit[MAXN][MAXN];

int rooms[MAXN][MAXN];

int roomsCopy[MAXN][MAXN];

int path[MAXN][MAXN];

int second;

struct Node {
    int x, y;
    int step;

    Node(int _x, int _y) {
        x = _x;
        y = _y;
        step = 0;
    }

    Node() {}
};

int direction[4][2] = {{0,  1},
                       {1,  0},
                       {0,  -1},
                       {-1, 0}};

void init() {
    memset(visit, false, sizeof(visit));
    second = 0;
}

bool judge(int x, int y) {
    if (x > n - 1 || x < 0 || y > m - 1 || y < 0 || roomsCopy[x][y] == 'X' || visit[x][y]) return false;
    return true;
}

int bfs(int x, int y) {
    // 保留原有文件
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            roomsCopy[i][j] = rooms[i][j];
        }
    }
    std::queue<Node> nodeQueue;
    Node cur = Node(x, y), next;
    visit[x][y] = true;
    nodeQueue.push(cur);
    while (!nodeQueue.empty()) {
        cur = nodeQueue.front();
        nodeQueue.pop();
        char c = roomsCopy[cur.x][cur.y];
        // 如果已经到了目的地
        if (cur.x == n - 1 && cur.y == m - 1) {
            int num = 0;
            if (c >= '1' && c <= '9') {
                num += c - '0';
            }
            return cur.step + num;
        }
        // 如果是数字
        if (c >= '1' && c <= '9') {
            if (c == '1') {
                roomsCopy[cur.x][cur.y] = '.';
            } else {
                roomsCopy[cur.x][cur.y] = c - 1;
            }
            next.x = cur.x;
            next.y = cur.y;
            next.step = cur.step + 1;
            nodeQueue.push(next);
            continue;
        }
        // 如果是 .
        for (int i = 0; i < 4; i++) {
            next.x = cur.x + direction[i][0];
            next.y = cur.y + direction[i][1];
            next.step = cur.step + 1;
            if (!judge(next.x, next.y)) continue;
            visit[next.x][next.y] = true;
            path[next.x][next.y] = i;
            nodeQueue.push(next);
        }
    }
    return 0;
}

void print(int x, int y) {
    if (x == 0 && y == 0) return;
    // 反推路径
    int index = path[x][y];
    int _x = x - direction[index][0], _y = y - direction[index][1];
    print(_x, _y);
    printf("%ds:(%d,%d)->(%d,%d)\n", ++second, _x, _y, x, y);
    if (rooms[x][y] >= '1' && rooms[x][y] <= '9') {
        int cnt = rooms[x][y] - '0';
        for (int i = 0; i < cnt; ++i) {
            printf("%ds:FIGHT AT (%d,%d)\n", ++second, x, y);
        }
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
        int step = bfs(0, 0);
        // 如果有
        if (step) {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", step);
            print(n - 1, m - 1);
        } else {
            printf("God please help our poor hero.\n");
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