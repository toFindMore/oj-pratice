//
// Created by 周健 on 2020-08-09.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        if (N <= 0) return cells;
        vector<int> pre_v(cells);
        N = N % 14;
        if (N == 0) {
            N = 14;
        }
//        cout << N << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < pre_v.size(); j++) {
                if (j == 0 || j == pre_v.size() - 1) {
                    cells[j] = 0;
                    continue;
                }
                if (pre_v[j - 1] == 0 && pre_v[j + 1] == 0 || pre_v[j - 1] == 1 && pre_v[j + 1] == 1) {
                    cells[j] = 1;
                } else {
                    cells[j] = 0;
                }
            }
            pre_v = cells;
//            for (int j = 0; j < pre_v.size(); j++) {
//                cout << pre_v[j] << ",";
//            }
//            cout << endl;
        }
        return cells;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(0);
    vv.push_back(0);
    vv.push_back(1);
    vv.push_back(0);
    vv.push_back(0);
    vv.push_back(1);
    vv.push_back(0);
    s.prisonAfterNDays(vv, 1000000000);
    return 0;
}