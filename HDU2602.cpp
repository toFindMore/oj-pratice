//
// Created by 周健 on 2019-08-10.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

int main() {
    int t;
    cin >> t;
    int dp[MAX_N];
    int volume[MAX_N];
    int value[MAX_N];
    while (t--) {
        int n, v;
        memset(dp, 0, sizeof(dp));
        cin >> n >> v;
        for (int i = 1; i <= n; i++) {
            cin >> value[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> volume[i];
        }
        for (int i = 1; i <= n; i++) {
            for(int j=v;j >= volume[i];j--) {
                dp[j] = max(dp[j], dp[j-volume[i]] + value[i]);
            }
        }
        cout << dp[v] << endl;
    }
}

