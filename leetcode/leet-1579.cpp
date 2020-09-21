//
// Created by 周健 on 2020-09-07.
//
#include<vector>
#include<stdio.h>
#include <algorithm>

using namespace std;

class Solution {

    const static int SIZE = 100005;

    int link[SIZE], linkAlice[SIZE], linkBob[SIZE];

    int find(int x, int _link[]) {
        if (x == _link[x]) return x;
        return _link[x] = find(_link[x], _link);
    }

    bool merge(int x, int y, int _link[]) {
        int r1 = find(x, _link);
        int r2 = find(y, _link);
        if (r1 != r2) {
            _link[r1] = r2;
            return true;
        }
        return false;
    }

private:

public:
    int maxNumEdgesToRemove(int n, vector<vector<int> > &edges) {
        // init
        for (int i = 1; i <= n; i++) link[i] = i;
        vector<vector<int> > v1, v2, v3;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == 1) v1.push_back(edges[i]);
            else if (edges[i][0] == 2) v2.push_back(edges[i]);
            else v3.push_back(edges[i]);
        }
        int res = 0;
        for (int i = 0; i < v3.size(); i++) if (!merge(v3[i][1], v3[i][2], link)) ++res;
        for (int i = 1; i <= n; i++) linkAlice[i] = link[i], linkBob[i] = link[i];
        for (int i = 0; i < v1.size(); i++) if (!merge(v1[i][1], v1[i][2], linkAlice)) ++res;
        for (int i = 0; i < v2.size(); i++) if (!merge(v2[i][1], v2[i][2], linkBob)) ++res;
        for (int i = 1; i <= n; i++) printf("%d ", linkAlice[i]);
        printf("\n");
        for (int i = 1; i <= n; i++) printf("%d ", linkBob[i]);
        for (int i = 1, tmp = find(linkAlice[1],linkAlice); i <= n; i++) if (tmp != find(linkAlice[i],linkAlice)) return -1;
        for (int i = 1, tmp = find(linkBob[1], linkBob); i <= n; i++) if (tmp != find(linkBob[i], linkBob)) return -1;
        return res;
    }
};


int main() {
    return 0;
}