//
// Created by 周健 on 2019-08-28.
//
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Tree {
    vector<Tree *> node;
    int v;
};

int main() {
    int T;
    int n, m;
    int u, v, dis;
    cin >> T;
    // 是否访问过
    int vis[40004];
    // 询问记录
    map<int, map<int, int> > qq;
    // 路径映射
    map<int, map<int, int> > mm;
    while (T--) {
        mm.clear();
        qq.clear();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &u, &v, &dis);
            mm[u][v] = mm[v][u] = dis;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            qq[u][v] = qq[v][u] = 1;
        }
        for()
    }
    return 0;
}