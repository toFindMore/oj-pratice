//
// Created by 周健 on 2019-12-23.
//
#include <stdio.h>
#include <algorithm>

using namespace std;

const int SIZE = 1005;

struct Relation {
    double J, F;
};

int CMP(Relation r1, Relation r2) {
    return r1.J / r1.F > r2.J / r2.F;
};

int main() {
    Relation relation[SIZE];
    int M, N;
    while (scanf("%d%d", &M, &N) && !(M == -1 && N == -1)) {
        for (int i = 0; i < N; i++) {
            scanf("%lf%lf", &relation[i].J, &relation[i].F);
        }
        sort(relation, relation + N, CMP);
        double res = 0;
        int cnt = -1;
        while (++cnt < N && relation[cnt].F <= M) {
            res += relation[cnt].J;
            M -= relation[cnt].F;
        }
        if (cnt < N) {
            res += (double) M / relation[cnt].F * relation[cnt].J;
        }
        printf("%.3f\n", res);
    }
    return 0;
}
