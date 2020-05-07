//
// Created by 周健 on 2020-05-07.
//
#include <stdio.h>

int main() {
    char str[205];
    while (scanf("%s", &str) != EOF) {
        int x = 310;
        int y = 420;
        int status = 0;
        printf("300 420 moveto\n310 420 lineto\n");
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == 'A') {
                if (status == 0) {
                    y -= 10;
                } else if (status == 1) {
                    x -= 10;
                } else if (status == 2) {
                    y += 10;
                } else if (status == 3) {
                    x += 10;
                }
                status = (status + 1) % 4;
            } else {
                if (status == 0) {
                    y += 10;
                } else if (status == 1) {
                    x += 10;
                } else if (status == 2) {
                    y -= 10;
                } else if (status == 3) {
                    x -= 10;
                }
                status = status - 1 != -1 ? status - 1 : 3;
            }
            printf("%d %d lineto\n", x, y);
        }
        printf("stroke\nshowpage\n");
    }
    return 0;
}
