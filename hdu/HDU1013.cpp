//
// Created by 周健 on 2020-01-15.
//
#include <stdio.h>
#include <cstring>

int transfer(char str[]) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - '0';
    }
    return sum;
}

int transfer(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    char str[10001];
    while (gets(str) != NULL && strcmp(str, "0")) {
        int tmp = transfer(str);
        while(tmp >=10) {
            tmp = transfer(tmp);
        }
        printf("%d\n", tmp);
    }
    return 0;
}
