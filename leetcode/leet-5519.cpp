//
// Created by 周健 on 2020-09-20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    const static int SIZE = 15;

    const static int INF = 0x3FFFFFFF;

    const static long long MOD = 1000000007;

    long long mapValue[SIZE][SIZE][2];

    void init(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mapValue[i][j][0] = mapValue[i][j][1] = -INF;
            }
        }
        mapValue[0][0][0] = grid[0][0];
        for (int i = 1; i < row; i++) {
            mapValue[i][0][0] = mapValue[i - 1][0][0] * grid[i][0];
        }
        for (int i = 1; i < col; i++) {
            mapValue[0][i][0] = mapValue[0][i - 1][0] * grid[0][i];
        }
    }

public:
    int maxProductPath(vector<vector<int>> &grid) {
        init(grid);
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                vector<long long> vv;
                if (mapValue[i - 1][j][0] != -INF) {
                    vv.push_back(mapValue[i - 1][j][0] * grid[i][j]);
                }
                if (mapValue[i - 1][j][1] != -INF) {
                    vv.push_back(mapValue[i - 1][j][1] * grid[i][j]);
                }
                if (mapValue[i][j - 1][0] != -INF) {
                    vv.push_back(mapValue[i][j - 1][0] * grid[i][j]);
                }
                if (mapValue[i][j - 1][1] != -INF) {
                    vv.push_back(mapValue[i][j - 1][1] * grid[i][j]);
                }
                sort(vv.begin(), vv.end());
                mapValue[i][j][0] = vv[vv.size() - 1];
                mapValue[i][j][1] = vv[0];
            }
        }
        return mapValue[row - 1][col - 1][0] >= 0 ? mapValue[row - 1][col - 1][0] % MOD : -1;
    }
};