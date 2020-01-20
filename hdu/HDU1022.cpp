//
// Created by 周健 on 2020-01-20.
//
#include <stdio.h>
#include <stack>

const int SIZE = 11;

int main() {
    char o1[SIZE], o2[SIZE];
    int n;
    while (scanf("%d%s%s", &n, o1, o2) != EOF) {
        int p2 = 0, p1 = 0;
        std::stack<char> railway;
        // 1 in ; 0 out
        int result[SIZE * 2];
        int cnt = -1;
        bool flag = true;
        for (; p2 < n; p2++) {
            while (railway.empty() || o2[p2] != railway.top()) {
                if (p1 == n) break;
                railway.push(o1[p1++]);
                result[++cnt] = 1;
            }
            if (railway.empty() || railway.top() != o2[p2]) {
                printf("No.\n");
                flag = false;
                break;
            }
            railway.pop();
            result[++cnt] = 0;
        }
        if (flag) {
            printf("Yes.\n");
            for (int i = 0; i <= cnt; i++) {
                if (result[i]) {
                    printf("in\n");
                } else {
                    printf("out\n");
                }
            }
        }
        printf("FINISH\n");
    }
    return 0;
}
