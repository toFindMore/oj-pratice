//
// Created by 周健 on 2020-09-06.
//
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {

    long long dp[105][205];

    int visit[105][205];

    const int MOD = 1000000007;

    int maxFuel;

private:

    long long dis(long long s1, long long s2) {
        if (s1 > s2) return s1 - s2;
        return s2 - s1;
    }

    long long dfs(int num, int fuel, vector<int> &locations) {
        if (fuel > maxFuel) return 0;
        if (visit[num][fuel]) return dp[num][fuel];
        visit[num][fuel] = 1;
        for (int i = 0; i < locations.size(); i++) {
            if (num != i) {
                dp[num][fuel] += dfs(i, fuel + dis(locations[num], locations[i]), locations);
                dp[num][fuel] %= MOD;
            }
        }
        return dp[num][fuel];
    }

public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        memset(dp, 0, sizeof(dp));
        memset(visit, 0, sizeof(visit));
        dp[start][fuel] = 1;
        maxFuel = fuel;
        long long res = 0;
        for (int i = 0; i <= fuel; i++) {
            res += dfs(finish, i, locations);
            res %= MOD;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(3);
    s.countRoutes(vv, 0, 2, 40);
    return 0;
}