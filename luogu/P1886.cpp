//
// Created by 周健 on 2/25/21.
//
#include<iostream>
#include<vector>

using namespace std;

int st[1000005][20];

void initRmqMin(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) st[i][0] = st[i][0] = nums[i];
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < len; i++) {
            if (i + (1 << j) - 1 < len) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j-1))][j - 1]);
            }
        }
    }
}

void initRmqMax(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) st[i][0] = st[i][0] = nums[i];
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < len; i++) {
            if (i + (1 << j) - 1 < len) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j-1))][j - 1]);
            }
        }
    }
}

int queryMin(int l, int r) {
    int cnt = 0;
    while (1 << (cnt + 1) <= r - l + 1) ++cnt;
    return min(st[l][cnt], st[r - (1 << cnt) + 1][cnt]);
}

int queryMax(int l, int r) {
    int cnt = 0;
    while (1 << (cnt + 1) <= r - l + 1) ++cnt;
    return max(st[l][cnt], st[r - (1 << cnt) + 1][cnt]);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    vector<int> minAns(n - k + 1);
    vector<int> maxAns(n - k + 1);
    initRmqMin(nums);
    for (int i = 0; i < n; i++) {
        int l = i;
        int r = i + k - 1;
        if (r < n) {
            minAns[i] = queryMin(l, r);
//            maxAns[i] = queryMax(l, r);
        }
    }
    initRmqMax(nums);
    for (int i = 0; i < n; i++) {
        int l = i;
        int r = i + k - 1;
        if (r < n) {
            maxAns[i] = queryMax(l, r);
        }
    }

    for (int i = 0; i < n - k + 1; i++) {
        if (i != 0) printf(" ");
        printf("%d", minAns[i]);
    }
    printf("\n");

    for (int i = 0; i < n - k + 1; i++) {
        if (i != 0) printf(" ");
        printf("%d", maxAns[i]);
    }
    printf("\n");
    return 0;
}

////
//// Created by 周健 on 2019-08-02.
////
//#include <iostream>
//#include <queue>
//#include <stdlib.h>
//#include <cstring>
//#include <map>
//#include <set>
//#include <vector>
//#include <stack>
//#include <cmath>
//#include <algorithm>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//void insertMax(deque<pair<int, int> > &deq, int idx, int value) {
//    if (deq.empty()) deq.push_back(make_pair(value, idx));
//    else {
//        while (!deq.empty()) {
//            if (value >= deq.back().first) deq.pop_back();
//            else break;
//        }
//        deq.push_back(make_pair(value, idx));
//    }
//}
//
//void insertMin(deque<pair<int, int> > &deq, int idx, int value) {
//    if (deq.empty()) deq.push_back(make_pair(value, idx));
//    else {
//        while (!deq.empty()) {
//            if (value <= deq.back().first) deq.pop_back();
//            else break;
//        }
//        deq.push_back(make_pair(value, idx));
//    }
//}
//
//
//int vec[1000006];
//int minAns[1000006], maxAns[1000006];
//
//void print(int *vec, int n) {
//    cout << vec[0];
//    for (int i = 1; i < n; i++) {
//        printf(" %d", vec[i]);
//    }
//    cout << endl;
//}
//
//int main() {
//    int n, k;
//    cin >> n >> k;
//    for (int i = 0; i < n; i++) scanf("%d", &vec[i]);
//    deque<pair<int, int> > maxQ, minQ;
//    for (int i = 0; i < k; i++) {
//        insertMax(maxQ, i, vec[i]);
//        insertMin(minQ, i, vec[i]);
//    }
//    minAns[0] = minQ.front().first;
//    maxAns[0] = maxQ.front().first;
//    int cnt = 1;
//    for (int i = k; i < n; i++) {
//        // 刪除队首元素
//        while (!maxQ.empty() && maxQ.front().second <= i - k) maxQ.pop_front();
//        while (!minQ.empty() && minQ.front().second <= i - k) minQ.pop_front();
//        insertMax(maxQ, i, vec[i]);
//        insertMin(minQ, i, vec[i]);
//        minAns[cnt] = minQ.front().first;
//        maxAns[cnt++] = maxQ.front().first;
//    }
//    // print
//    print(minAns, n - k + 1);
//    print(maxAns, n - k + 1);
//    return 0;
//
//}

//
// Created by 周健 on 2019-08-02.


