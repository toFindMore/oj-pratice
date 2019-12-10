//
// Created by 周健 on 2019-08-18.
//
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

char trans(int c) {
    switch (c) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
    }
}

int main() {
    // please write your code here
    string s;
    string s1, s2;
    while (cin >> s) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '-') {
                s1 = s.substr(0, i);
                s2 = s.substr(i + 1);
                break;
            }
        }
        int len1 = s1.size();
        int len2 = s2.size();
        string sss;
        for (int i = 0; i < len1 - len2; i++) {
            sss += "0";
        }
        s2 = sss + s2;
        int pos = 0;
        for (int i = len1 - 1; i >= 0; i--) {
            int a = s1[i] - '0';
            int b = s2[i] - '0';
            int k = a - pos - b;
            if (k >= 0) {
                s1[i] = k + '0';
                pos = 0;
            } else {
                s1[i] = k + 10 + '0';
                pos = 1;
            }
        }
        cout << s1;
    }
    return 0;
}
