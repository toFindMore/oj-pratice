//
// Created by 周健 on 2020-09-04.
//
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
private:
    bool isOK(int i) {
        while (i) {
            if (i % 10 == 0) {
                return false;
            }
            i /= 10;
        }
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for (int i = 1; i < n; i++) {
            if (isOK(i) && isOK(n - i)) {
                res.push_back(i);
                res.push_back(n - i);
                return res;
            }
        }
        return res;
    }
};

