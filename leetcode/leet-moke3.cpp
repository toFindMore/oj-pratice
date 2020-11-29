//
// Created by 周健 on 2020-09-05.
//
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {

    int res = -1;

    void forward(vector<int> &heights, int cur, int bricks, int ladders) {
        if (cur == heights.size() - 1) {
            res = heights.size() - 1;
            return;
        }
        if (heights[cur + 1] <= heights[cur]) forward(heights, cur + 1, bricks, ladders);
        else {
            // 如果不能再前进了
            if (ladders <= 0 && bricks < heights[cur + 1] - heights[cur]) {
                res = res < cur ? cur : res;
                return;
            }
            // 用梯子
            if (ladders > 0) {
                forward(heights, cur + 1, bricks, ladders - 1);
            }
            // 用砖
            if (bricks >= heights[cur + 1]) {
                forward(heights, cur + 1, bricks - heights[cur + 1] + heights[cur], ladders - 1);
            }
        }
    }

public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        forward(heights, 0, bricks, ladders);
        return res;
    }
};