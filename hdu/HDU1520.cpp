//
// Created by 周健 on 1/15/21.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> childMap[6005];
int happyValue[6005];
int dp[6005][2];

void DP(int root) {
    if (childMap[root].size() == 0) {
        dp[root][0] = 0, dp[root][1] = happyValue[root];
        return;
    }
    vector<int> childSet = childMap[root];
    dp[root][0] = 0;
    dp[root][1] = happyValue[root];
    for (int v : childSet) {
        DP(v);
        dp[root][0] += max(dp[v][0], dp[v][1]);
        dp[root][1] += dp[v][0];
    }
}

int main() {
    int N, c, s, root;
    while(~scanf("%d", &N)) {
        for(int i = 0;i<6005;i++) childMap[i].clear();
        vector<bool> isRoot(N + 1, true);
        for (int i = 1; i <= N; i++) scanf("%d", &happyValue[i]);
        cin >> c >> s;
        while (!(c == 0 && s == 0)) {
            childMap[s].push_back(c);
            isRoot[c] = false;
            scanf("%d%d", &c, &s);
        }
        int sum = 0;
        for (int i = 1; i <= N; i++) if (isRoot[i]) root = i, DP(root), sum += max(dp[root][0], dp[root][1]);
        cout << sum << endl;
    }
    return 0;
}
