//
// Created by 周健 on 2019-09-02.
//
#include <iostream>
#include <cmath>

using namespace std;
const int SIZE = 40000;

int main() {
    int N;
    int dp[SIZE] = {0};
    dp[0]=1;
    for (int i = 1; i <= 3; i++) {
        for (int j = i; j <= 32769; j++) {
            dp[j] += dp[j - i];
        }
    }
    while(cin >> N) {
        printf("%d\n", dp[N]);
    }
    return 0;
}
