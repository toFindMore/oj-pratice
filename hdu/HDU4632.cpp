//
// Created by 周健 on 12/7/20.
//
#include <iostream>

using namespace std;

const int SIZE = 1005;
int dp[SIZE][SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) fill(dp[i], dp[i] + SIZE, 0);
}

int main() {
    int caseNum, end;
    string str;
    cin >> caseNum;
    for (int i = 1; i <= caseNum; i++) {
        cin >> str;
        init();
        for (int i = 0; i < str.size(); i++) dp[i][i] = 1;
        for (int slice = 2; slice <= str.size(); slice++) {
            for (int i = 0; i + slice - 1 < str.size(); i++) {
                end = i + slice - 1;
                dp[i][end] = (dp[i + 1][end] + dp[i][end - 1] - dp[i + 1][end - 1] + 10007) % 10007;
                if (str[i] == str[end]) {
                    dp[i][end] = (dp[i][end] + dp[i + 1][end - 1] + 1) % 10007;
                }
            }
        }
        cout << "Case " << i << ": " << dp[0][str.size() - 1] << endl;
    }
    return 0;
}
