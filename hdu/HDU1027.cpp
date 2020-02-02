//
// Created by 周健 on 2020-02-02.
//
#include <stdio.h>
#include <string.h>
#include <queue>

const int MAXN = 1005;

int n, m;

bool visit[MAXN];

int k[9];

void init() {
    k[0] = 1;
    for (int i = 1; i <= 7; i++) {
        k[i] = k[i - 1] * i;
    }
}

int main() {
    init();
    std::queue<int> q;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(visit, false, sizeof(visit));
        int nCpy = n;
        // 9以上的话不变
        if (n >= 9) {
            for (int i = 1; i <= n - 8; i++) {
                q.push(i);
                visit[i] = true;
            }
            nCpy = 8;
        }
        // 遍历n
        for (int i = nCpy; i >= 1; --i) {
            int index = (m + k[i - 1] - 1) / k[i - 1];
            m = (m + k[i - 1] - 1) % k[i - 1] + 1;
            for (int t = 1, cnt = 0; t <= n; t++) {
                if (!visit[t]) ++cnt;
                if (cnt == index) {
                    visit[t] = true;
                    q.push(t);
                    break;
                }
            }
        }
        printf("%d", q.front());
        q.pop();
        while (!q.empty()) {
            printf(" %d", q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}
//9 8 7 6 5 4 3 2 1