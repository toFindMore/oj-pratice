//
// Created by 困呐～ on 2020/1/6.
//
#include <stdio.h>
#include <string.h>

// 10个数字 5行 4位
char str[10][5][4];

void init() {
    // 0
    strcpy(str[0][0], "000");
    strcpy(str[0][1], "0 0");
    strcpy(str[0][2], "0 0");
    strcpy(str[0][3], "0 0");
    strcpy(str[0][4], "000");
    // 1
    strcpy(str[1][0], " 1 ");
    strcpy(str[1][1], "11 ");
    strcpy(str[1][2], " 1 ");
    strcpy(str[1][3], " 1 ");
    strcpy(str[1][4], "111");
    // 2
    strcpy(str[2][0], "222");
    strcpy(str[2][1], "  2");
    strcpy(str[2][2], "222");
    strcpy(str[2][3], "2  ");
    strcpy(str[2][4], "222");
    // 3
    strcpy(str[3][0], "333");
    strcpy(str[3][1], "  3");
    strcpy(str[3][2], "333");
    strcpy(str[3][3], "  3");
    strcpy(str[3][4], "333");
    // 4
    strcpy(str[4][0], "4 4");
    strcpy(str[4][1], "4 4");
    strcpy(str[4][2], "444");
    strcpy(str[4][3], "  4");
    strcpy(str[4][4], "  4");
    // 5
    strcpy(str[5][0], "555");
    strcpy(str[5][1], "5  ");
    strcpy(str[5][2], "555");
    strcpy(str[5][3], "  5");
    strcpy(str[5][4], "555");
    // 6
    strcpy(str[6][0], "666");
    strcpy(str[6][1], "6  ");
    strcpy(str[6][2], "666");
    strcpy(str[6][3], "6 6");
    strcpy(str[6][4], "666");
    // 7
    strcpy(str[7][0], "777");
    strcpy(str[7][1], "  7");
    strcpy(str[7][2], "  7");
    strcpy(str[7][3], " 7 ");
    strcpy(str[7][4], "7  ");
    // 8
    strcpy(str[8][0], "888");
    strcpy(str[8][1], "8 8");
    strcpy(str[8][2], "888");
    strcpy(str[8][3], "8 8");
    strcpy(str[8][4], "888");
    // 9
    strcpy(str[9][0], "999");
    strcpy(str[9][1], "9 9");
    strcpy(str[9][2], "999");
    strcpy(str[9][3], "  9");
    strcpy(str[9][4], "999");;
}

int main() {
    init();
    int a[11];
    int n;
    int cnt = 0;
    scanf("%d", &n);
    while (true) {
        int k = n % 10;
        a[cnt] = k;
        n /= 10;
        cnt++;
        if (n == 0) {
            break;
        }
    }


    for (int k = 0; k < 5; k++) {
        for (int i = cnt - 1; i >= 0; i--) {
            if (i != cnt - 1) {
                printf("    ");
            }
            printf("%s", str[a[i]][k]);

        }
        if (k != 4) {
            printf("\n");
        }
    }
    return 0;
}
