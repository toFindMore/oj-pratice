//
// Created by 周健 on 2020-08-23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int> &rounds) {

        vector<int> res;
        int start = rounds[0];
        int end = rounds[rounds.size() - 1];
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                res.push_back(i);
            }
        } else {
            for (int i = 1; i <= end; i++) {
                res.push_back(i);
            }
            for (int i = start; i <= n; i++) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(3);
    vv.push_back(5);
    vv.push_back(7);
//    vv.push_back(0);
//    vv.push_back(0);
//    vv.push_back(1);
//    vv.push_back(0);
    vector<int> vvv = s.mostVisited(7, vv);
    for(int i=0;i<vvv.size();i++) {
        cout << vvv[i] << " ";
    }

    return 0;
}