//
// Created by 周健 on 11/9/20.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int> > minQueue;
        int len = heights.size();
        int sum = 0;
        for (int i = 1; i < len; i++) {
            int h = heights[i] - heights[i - 1];
            if (h > 0) {
                minQueue.push(h);
                if (minQueue.size() > ladders) {
                    sum += minQueue.top();
                    minQueue.pop();
                }
                if (sum > bricks) {
                    return i - 1;
                }
            }
        }
        return len - 1;
    }
};

int main() {

    return 0;
}
