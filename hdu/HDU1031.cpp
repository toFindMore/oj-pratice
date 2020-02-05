//
// Created by 周健 on 2020-02-05.
//
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int SIZE = 10005;

const double C = 0.000001;

struct Data {
    double value;
    int index;
} data[SIZE];

bool cmp(Data a, Data b) {
    if (fabs(a.value - b.value) < C) return a.index < b.index;
    if (a.value > b.value) return true;
    return false;
}

bool cmp1(int a, int b) {
    return a > b;
}

void init(int m) {
    for (int i = 0; i < m; i++) {
        data[i].index = i + 1;
        data[i].value = 0;
    }
}

int main() {
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF) {
        init(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                double tmp;
                scanf("%lf", &tmp);
                data[j].value += tmp;
            }
        }
        sort(data, data + m, cmp);
        int tmpArr[SIZE];
        for (int j = 0; j < k; j++) {
            tmpArr[j] = data[j].index;
        }
        sort(tmpArr, tmpArr + k, cmp1);
        printf("%d", tmpArr[0]);
        for (int j = 1; j < k; j++) {
            printf(" %d", tmpArr[j]);
        }
        printf("\n");
    }
    return 0;
}

