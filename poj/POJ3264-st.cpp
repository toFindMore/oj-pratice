//
// Created by 周健 on 3/25/21.
//
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 5e4 + 5;

int dpMax[SIZE][20], dpMin[SIZE][20];

int arr[SIZE];

int n, m, l, r;

void init() {
    for (int i = 1; i <= n; i++) {
        dpMax[i][0] = dpMin[i][0] = arr[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if ((j + (1 << i)) - 1 > n) break;
            dpMax[j][i] = max(dpMax[j][i - 1], dpMax[j + (1 << (i - 1))][i - 1]);
            dpMin[j][i] = min(dpMin[j][i - 1], dpMin[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int queryMax(int l, int r) {
    int wi = r - l + 1;
    int cnt = 0;
    while((1 << cnt) <= wi) {
        cnt++;
    }
    int w = cnt - 1;
    return max(dpMax[l][w], dpMax[r - (1 << w) + 1][w]);
}

int queryMin(int l, int r) {
    int wi = r - l + 1;
    int cnt = 0;
    while((1 << cnt) <= wi) {
        cnt++;
    }
    int w = cnt - 1;
    return min(dpMin[l][w], dpMin[r - (1 << w) + 1][w]);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    init();
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        cout << queryMax(l, r) -  queryMin(l, r) << endl;
    }
    return 0;
}
