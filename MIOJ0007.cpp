//
// Created by 周健 on 2019-08-27.
//
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int d;
    char c;
    int cnt = -1;
    int num[101] = {0};
    // please write your code here
    while (cin >> d) {
        cin >> c;
        if (d > 0) {
            num[d] = 1;
            ++cnt;
        }
        if (c == '\n') break;
    }
    for (int i = 1; i <= cnt + 2; i++) {
        if (num[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}