//
// Created by 周健 on 2020-08-30.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;



class Solution {
    struct DP {
        long long positiveWeight;
        long long negativeWeight;
    };

    DP dp[100005];

public:
    int getMaxLen(vector<int> &nums) {
        if (nums[0] < 0) {
            dp[0].negativeWeight = 1;
            dp[0].positiveWeight = 0;
        } else if (nums[0] > 0) {
            dp[0].negativeWeight = 0;
            dp[0].positiveWeight = 1;
        } else {
            dp[0].negativeWeight = 0;
            dp[0].positiveWeight = 0;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (dp[i - 1].positiveWeight == 0 && dp[i - 1].negativeWeight != 0) {
                    dp[i].positiveWeight = 1;
                    dp[i].negativeWeight = dp[i - 1].negativeWeight + 1;
                } else if (dp[i - 1].positiveWeight != 0 && dp[i - 1].negativeWeight == 0) {
                    dp[i].positiveWeight = dp[i - 1].positiveWeight + 1;
                    dp[i].negativeWeight = 0;
                } else if (dp[i - 1].positiveWeight == 0 && dp[i - 1].negativeWeight == 0) {
                    dp[i].positiveWeight = 1;
                    dp[i].negativeWeight = 0;
                } else {
                    dp[i].positiveWeight = dp[i - 1].positiveWeight + 1;
                    dp[i].negativeWeight = dp[i - 1].negativeWeight + 1;
                }
            } else if (nums[i] < 0) {
                if (dp[i - 1].positiveWeight == 0 && dp[i - 1].negativeWeight != 0) {
                    dp[i].positiveWeight = dp[i - 1].negativeWeight + 1;
                    dp[i].negativeWeight = 1;
                } else if (dp[i - 1].positiveWeight != 0 && dp[i - 1].negativeWeight == 0) {
                    dp[i].positiveWeight = 0;
                    dp[i].negativeWeight = dp[i - 1].positiveWeight + 1;
                } else if (dp[i - 1].positiveWeight == 0 && dp[i - 1].negativeWeight == 0) {
                    dp[i].positiveWeight = 0;
                    dp[i].negativeWeight = 1;
                } else {
                    dp[i].positiveWeight = dp[i - 1].negativeWeight + 1;
                    dp[i].negativeWeight = dp[i - 1].positiveWeight + 1;
                }
            } else {
                dp[i].negativeWeight = 0;
                dp[i].positiveWeight = 0;
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
//            cout << dp[i].positiveWeight << endl;
            if (dp[i].positiveWeight > res) {
                res = dp[i].positiveWeight;
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vv;
    // 1,2,3,5,-6,4,0,10
    vv.push_back(0);
    vv.push_back(1);
    vv.push_back(-2);
    vv.push_back(-3);
    vv.push_back(-4);
    cout << s.getMaxLen(vv);
    return 0;
}