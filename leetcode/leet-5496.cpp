//
// Created by 周健 on 2020-08-23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 1 2 3 4 5
class Solution {
public:
    int maxCoins(vector<int> &piles) {
        int sum = 0;
        bool flag = true;
        sort(piles.begin(), piles.end());
        for (int i = piles.size() - 2; i >= piles.size() / 3; i++) {
            if(flag) {
                sum +=piles[i];
                flag = false;
            } else {
                flag = true;
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}