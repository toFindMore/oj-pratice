//
// Created by 周健 on 2019-08-01.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct CMP {
    bool operator()(int &a, int &b) {
        return a > b;
    }
};

int main() {
    int n, m;
    int in[10005] = {0};
    while(scanf("%d%d", &n, &m)!=EOF) {
        fill(in,in+10005,0);
        vector<pair<int, int> > vv;
        for (int i = 0; i < m; i++) {
            int k1, k2;
            scanf("%d%d", &k1, &k2);
            pair<int, int> p(k1, k2);
            vv.push_back(p);
            in[k2] += 1;
        }
        priority_queue<int, vector<int>, CMP> qq;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                qq.push(i);
            }
        }
        vector<int> result;
        while (!qq.empty()) {
            int k = qq.top();
            result.push_back(k);
            qq.pop();
            for (int i = 0; i < vv.size(); i++) {
                if (vv[i].first == k) {
                    int h = vv[i].second;
                    in[h] -= 1;
                    if (in[h] == 0) {
                        qq.push(h);
                    }
                }
            }
        }
        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                printf("%d", result[i]);
            } else {
                printf(" %d", result[i]);
            }
        }
        printf("\n");
    }
    return 0;
}