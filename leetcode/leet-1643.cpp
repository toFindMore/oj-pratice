//
// Created by 周健 on 11/9/20.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

    int C[31][31];

    void init() {
        for (int i = 1; i < 16; i++) {
            C[i][0] = 1;
            C[i][1] = i;
            C[i][i] = 1;
        }
        for (int i = 2; i < 16; i++) {
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
    }

public:
    string kthSmallestPath(vector<int> &destination, int k) {
        init();
        int V = destination[0];
        int H = destination[1];
        int sum = H + V;
        int h = 0, v = 0;
        string res = "";
        while (res.length() != sum) {
            if (h == H) {
                res += 'V';
                continue;
            }
            if (v == V) {
                res += 'H';
                continue;
            }
            if (k > C[H + V - h - v - 1][H - h - 1]) {
                res += 'V';
                k -= C[H + V - h - v - 1][H - h - 1];
                v += 1;
            } else {
                res += 'H';
                h += 1;
            }
        }
        return res;
    }
};

int main() {
    vector<int> param1;
    param1.push_back(15);
    param1.push_back(15);
    Solution s;
//    cout << s.kthSmallestPath(param1, 1) << endl << endl;
//    cout << s.kthSmallestPath(param1, 2) << endl << endl;
    cout << s.kthSmallestPath(param1, 155117520) << endl << endl;
    return 0;
}
