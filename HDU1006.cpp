//
// Created by 周健 on 2019-12-12.
//
#include <stdio.h>
#include <math.h>

int main() {
    int degree;
    while (scanf("%d", &degree) && degree != -1) {
        degree = degree * 120;
        int hour = 0;
        int minute = 0;
        int second = 0;
        int resTime = 0;
        for (int i = 0; i <= 43199; i++, minute++, second++, hour++) {
            if (second == 60) {
                second = 0;
            }
            if (minute == 3600) {
                minute = 0;
            }
            double doubleH = (double) hour;
            double doubleM = (double) minute * 12;
            double doubleS = (double) second * 720;
            if (abs(doubleH - doubleM) >= degree && abs(43200 - abs(doubleH - doubleM)) >= degree
                && abs(doubleH - doubleS) >= degree && abs(43200 - abs(doubleH - doubleS)) >= degree
                && abs(doubleS - doubleM) >= degree && abs(43200 - abs(doubleS - doubleM)) >= degree) {
                ++resTime;
            }
        }
        printf("%.3lf\n", (double) resTime / 432);
    }
    return 0;
}