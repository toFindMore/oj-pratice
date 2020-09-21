//
// Created by zhoujian on 2020/9/8.
//
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 105;

int dfn[SIZE], low[SIZE], cutP[SIZE];
bool vis[SIZE];
vector<int> node[SIZE];
int timestamp = 0;

void tarjan(int cur, int fa) {
    dfn[cur] = ++timestamp;
    low[cur] = timestamp;
    vis[cur] = true;
    for (int i = 0; i < node[cur].size(); i++) {
        int next = node[cur][i];
        if (next == fa) continue;
        // 被访问过了
        if (vis[next]) {
            low[cur] = min(low[cur], low[next]);
        } else {
            tarjan(next, cur);
            low[cur] = min(low[cur], low[next]);
            // 子节点的low大于等于自己的dfn，那么就是一个割顶
            if (low[next] >= dfn[cur]) {
                cutP[cur]++;
            }
        }
    }
}

int main() {
    int num;
    char str[10000];
    while (scanf("%d", &num), num) {
        // init
        for (int i = 0; i < SIZE; i++) node[i].clear(), vis[i] = false, cutP[i] = 0;
        int x;
        while (scanf("%d", &x), x) {
            cin.getline(str, 10000);
            int tmp = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] == ' ' || str[i] == '\n') {
                    if (tmp == 0) continue;
                    node[tmp].push_back(x), node[x].push_back(tmp);
                    tmp = 0;
                    continue;
                }
                tmp = tmp * 10 + str[i] - '0';
            }
            if (tmp != 0) node[tmp].push_back(x), node[x].push_back(tmp);
        }
        // main work start
        tarjan(1, 0);
        int res = 0;
        for (int i = 1; i <= num; i++) {
            if (i == 1) {
                if (cutP[1] >= 2) res++;
                continue;
            }
            if (cutP[i] >= 1) res++;
        }
        printf("%d\n", res);
        // main work end
    }
    return 0;
}
