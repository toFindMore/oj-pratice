//
// Created by 周健 on 2020-05-22.
//
#include <stdio.h>

int main() {
    int n, t;
    double d;
    scanf("%d%lf", &n, &d);
    char str[10];
    while (scanf("%d", &t) != EOF) {
        int h = 0, m = 0, s = 0;
        printf("%3d:", t);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            if (str[0] == '-') {
                flag = false;
                continue;
            }
            h += str[0] - '0';
            m += (str[2] - '0') * 10 + (str[3] - '0');
            s += (str[5] - '0') * 10 + (str[6] - '0');
        }
        if (!flag) {
            printf(" -\n");
            continue;
        }
        int sum = h * 3600 + m * 60 + s;
        sum = sum / d + 0.5;
        int minute = sum / 60;
        int second = sum % 60;
        printf("%2d:%02d min/km\n", minute, second);
    }
    return 0;
}
