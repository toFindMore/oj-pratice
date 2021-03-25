//
// Created by 周健 on 3/23/21.
//
#include <cstring>

using namespace std;

/*
* INIT: init();
* 注: tree[i][tk] > 0时表示单词存在, 当然也可赋予它更多含义;
*/
const int tk = 26, tb = 'a'; // tk叉; 这个模板是小写字母
const int N = 1010000; // N: 最大结点个数
int top, tree[N][tk + 1];

void init() {
    top = 1;
    memset(tree[0], 0, sizeof(tree[0]));
}

int find(char *s) {
    int pre, cur;
    // 遍历s
    for (pre = 0; *s; pre = cur, ++s) {
        // nxt 表示当前节点的序号
        cur = tree[pre][*s - tb];
        // 表示节点不存在
        if (0 == cur) {
            // do something
        }
    }
    return 0;
}

void insert(char *s, int rank = 1) {
    int pre, cur;
    // 遍历s
    for (pre = 0; *s; pre = cur, ++s) {
        cur = tree[pre][*s - tb];
        // 新建节点
        if (0 == cur) {
            tree[pre][*s - tb] = cur = top;
            memset(tree[top], 0, sizeof(tree[top]));
            top++;
        }
    }
    // tk = 26 这个位置可以别的信息
    tree[pre][tk] = rank;
}

// leetcode的亦或 421
// const int tk = 2, tb = 'a'; // tk叉; 这个模板是小写字母
//const int N = 10000; // N: 最大结点个数
//
//class Solution {
//
//    int top, tree[N * 32][tk + 1];
//
//    void init() {
//        top = 1;
//        memset(tree[0], 0, sizeof(tree[0]));
//    }
//
//    void insert(int num) {
//        int pre = 0, cur;
//        for(int i=30;i>=0;i--) {
//            int k = num >> i & 1;
//            cur = tree[pre][k];
//            if(0 == cur) {
//                tree[pre][k] = cur = top;
//                memset(tree[top], 0, sizeof(tree[top]));
//                top++;
//            }
//            pre = cur;
//        }
//    }
//
//    int solve(int num) {
//        int pre = 0, cur;
//        int ans = 0;
//        for(int i=30;i>=0;i--) {
//            int k = num >> i & 1;
//            cur = tree[pre][1-k];
//            // 节点不存在，那么走正常路
//            if(0 == cur) cur = tree[pre][k];
//            else cur = tree[pre][1-k], ans += (1<<i);
//            pre = cur;
//        }
//        return ans;
//    }
//
//public:
//    int findMaximumXOR(vector<int>& nums) {
//        init();
//        int ans = 0;
//        for(int num : nums) insert(num);
//        for(int num : nums) ans = max(ans, solve(num));
//        return ans;
//    }
//};