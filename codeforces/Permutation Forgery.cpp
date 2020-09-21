//
// Created by 周健 on 2020-09-06.
//
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
    int caseNum = 0, n;
    scanf("%d", &caseNum);
    while (caseNum--) {
        scanf("%d", &n);
        int tmp;
        stack<int> ss;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            ss.push(tmp);
        }
        bool flag = false;
        while (!ss.empty()) {
            if(!flag) {
                flag = true;
            } else {
                printf(" ");
            }
            printf("%d", ss.top());
            ss.pop();
        }
        printf("\n");
    }
    return 0;
}