//
// Created by 周健 on 2020-05-22.
//
#include <stdio.h>

const int SIZE = 105;

int main() {
    int m, n, k;
    char map[SIZE][SIZE];
    int stepMap[SIZE][SIZE];
    while (scanf("%d%d%d", &m, &n, &k) && !(m == 0 && n == 0 && k == 0)) {
        // init
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                stepMap[i][j] = 0;
            }
        }

        getchar();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%c", &map[i][j]);
            }
            getchar();
        }

        int x = 0, y = k - 1;
        int step = 0;
        while (true) {
            if (stepMap[x][y] == 0) {
                stepMap[x][y] = ++step;
            } else {
                printf("%d step(s) before a loop of %d step(s)\n", stepMap[x][y] - 1, step - stepMap[x][y] + 1);
                break;
            }
            if (map[x][y] == 'N') {
                x -= 1;
            } else if (map[x][y] == 'S') {
                x += 1;
            } else if (map[x][y] == 'E') {
                y += 1;
            } else {
                y -= 1;
            }
            if (x < 0 || x >= m || y < 0 || y >= n) {
                printf("%d step(s) to exit\n", step);
                break;
            }
//            for (int i = 0; i < m; i++) {
//                for (int j = 0; j < n; j++) {
//                    printf("%d", stepMap[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n");
        }
    }
    return 0;
}
