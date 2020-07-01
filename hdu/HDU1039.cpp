//
// Created by 周健 on 2020-07-01.
//
#include <stdio.h>
#include <string.h>

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

void printNo(char *str) {
    printf("<%s> is not acceptable.\n", str);
}

void printYes(char *str) {
    printf("<%s> is acceptable.\n", str);
}

int main() {
    char str[1005];
    while (scanf("%s", str) && strcmp(str, "end") != 0) {
        // It must contain at least one vowel.
        bool haveVowel = false;
        for (int i = 0; str[i] != '\0'; i++) {
            if (isVowel(str[i])) {
                haveVowel = true;
            }
        }
        if (!haveVowel) {
            printNo(str);
            continue;
        }
        // It cannot contain three consecutive vowels or three consecutive consonants.
        bool isConsecutiveForThree = false;
        if (str[0] != '\0' && str[1] != '\0') {
            char prePre = str[0], pre = str[1];
            for (int i = 2; str[i] != '\0'; i++) {
                // 都相等
                if (isVowel(prePre) == isVowel(pre) && isVowel(pre) == isVowel(str[i])) {
                    isConsecutiveForThree = true;
                    break;
                }
                prePre = pre;
                pre = str[i];
            }
        }
        if (isConsecutiveForThree) {
            printNo(str);
            continue;
        }
        // It cannot contain two consecutive occurrences of the same letter, except for 'ee' or 'oo'.
        bool isSameLettersForNeigh = false;
        if (str[0] != '\0') {
            char pre = str[0];
            for (int i = 1; str[i] != '\0'; i++) {
                // 都相等
                if (str[i] == pre && pre != 'e' && pre != 'o') {
                    isSameLettersForNeigh = true;
                    break;
                }
                pre = str[i];
            }
        }
        if (isSameLettersForNeigh) {
            printNo(str);
            continue;
        }
        printYes(str);
    }
    return 0;
}