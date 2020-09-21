//
// Created by 周健 on 2020-09-06.
//
#include <stdio.h>
#include <vector>

using namespace std;

const int SIZE = 100005;

vector<int> nodes[SIZE];

int maxDeep;
int maxValue;

void dfs01(int deep, int root, int target, int fa) {
    if (root == target) maxDeep = deep;
    for (int i = 0; i < nodes[root].size(); i++) {
        if (nodes[root][i] == fa) continue;
        dfs01(deep + 1, nodes[root][i], target, root);
    }
}

void dfs(int deep, int root, int fa) {
    if (deep > maxDeep) maxDeep = deep, maxValue = root;
    for (int i = 0; i < nodes[root].size(); i++) {
        if (nodes[root][i] == fa) continue;
        dfs(deep + 1, nodes[root][i], root);
    }
}

void solve() {
    int n, a, b, da, db;
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int j = 0; j < SIZE; ++j) nodes[j].clear();
    for (int i = 0, tmp1, tmp2; i < n - 1; i++) {
        scanf("%d%d", &tmp1, &tmp2);
        nodes[tmp1].push_back(tmp2);
        nodes[tmp2].push_back(tmp1);
    }
    // 如果Bob在Alice的射程里
    maxDeep = 0;
    dfs01(0, a, b, 0);
    if (maxDeep <= da) {
        puts("Alice");
        return;
    }
    // 求树的直径 两次dfs
    maxDeep = 0;
    dfs(0, 1, 0);
    maxDeep = 0;
    dfs(0, maxValue, 0);

    da = min(da, maxDeep);
    db = min(db, maxDeep);
    if(2*da < db) {
        puts("Bob");
    } else {
        puts("Alice");
    }
}

int main() {
    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        solve();
    }
    return 0;
}