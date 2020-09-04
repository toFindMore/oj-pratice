//
// Created by 周健 on 2020-08-30.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;


class Solution {
private:
    bool equal(vector<int> &arr, int index1, int index2, int len) {
        for (int i = 0; i < len; i++) {
            if (i + index1 >= arr.size() || i + index2 >= arr.size()) {
                return false;
            }
            if (arr[i + index1] != arr[i + index2]) {
                return false;
            }
        }
        return true;
    }

public:
    bool containsPattern(vector<int> &arr, int m, int k) {
        for (int i = 0; i < arr.size(); i++) {
            int j;
            for (j = 1; j < k; j++) {
//                cout << i << " " << i+j*m << endl;
                if (!equal(arr, i, i + j * m, m)) {
                    break;
                }
            }
            if (j == k) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vv;
    // 1,2,4,4,4,4
    // 1,2,1,2,1,1,1,3
    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(1);
    vv.push_back(2);
    vv.push_back(1);
    vv.push_back(1);
    vv.push_back(1);
    vv.push_back(3);
    cout << s.containsPattern(vv,2,3);
    return 0;
}
