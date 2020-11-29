//
// Created by 周健 on 2019-08-02.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <deque>

#define min(x, y) x>y?y:x
using namespace std;

class Solution {

    struct Node {
        int after, origin;
        Node(int _after, int _origin) {
            after = _after;
            origin = _origin;
        }
    };

    bool cmp(Node node1, Node node2) {
        if(node1.after < node2.after) return true;
        if(node1.after == node2.after)
    }
public:
    int minimumDeviation(vector<int> &nums) {
        vector<Node> numsV;
        for (int i = 0; i < nums.size(); i++) {
            int x = 1, pre;
            while (nums[i] % x == 0) pre = x, x *= 2;
            int tmp = nums[i];
            numsV.push_back(Node(nums[i] / pre, nums[i]));
        }
        sort(nums.begin(), nums.end());
        int endPoint = nums.size() - 1;
        int minNum = nums[endPoint] - nums[0];
        while (true) {
            if(nums[0] % 2 == 0) break;
            nums[0] = nums[0] * 2;
            sort(nums.begin(), nums.end());
            if(minNum < nums[endPoint] - nums[0]) break;
            minNum = nums[endPoint] - nums[0];
        }
        return minNum;
    }
};

int main() {
    vector<int> vv;
    vv.push_back(4);
    vv.push_back(9);
    vv.push_back(4);
    vv.push_back(5);
    Solution s;
    cout << s.minimumDeviation(vv);
    return 0;
}