//
// Created by 周健 on 2019-08-27.
//
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int SIZE = 100;

int main() {
    string a, b, c;
    int lenA, lenB, lenC;
    int dp[SIZE][SIZE];
    while (getline(cin, a, ',')) {
        getline(cin, b, ',');
        getline(cin, c);
        lenA = a.size();
        lenB = b.size();
        lenC = c.size();
        if (lenA + lenB != lenC) {
            printf("false\n");
            continue;
        }
        // 初始化
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= lenA; i++) {
            if (a[i - 1] == c[i - 1]) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i <= lenB; i++) {
            if (b[i - 1] == c[i - 1]) {
                dp[0][i] = 1;
            } else {
                break;
            }
        }
        // dp 阶段
        for (int i = 1; i <= lenA; i++) {
            for (int j = 1; j <= lenB; j++) {
                if(c[i+j-1] == a[i-1] && dp[i-1][j]) {
                    dp[i][j] = 1;
                }
                if(c[i+j-1] == b[j-1] && dp[i][j-1]) {
                    dp[i][j] = 1;
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }

        if(dp[lenA][lenB]) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}