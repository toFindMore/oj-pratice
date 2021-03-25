//
// Created by 周健 on 3/25/21.
//
#include <iostream>
#include <algorithm>

const double EPS = 1e-6;

using namespace std;

const int SIZE = 2e5 + 5;

struct node {
    // val 维护相应的值, 最大值
    int l, r, val;
    // lazy 标识下面每个值需要加的数
    int lazy, len;
} segTree[SIZE * 4];

int h, w, n;

// 更新父节点i
void pushUp(int i) {
    segTree[i].val = max(segTree[i << 1].val, segTree[(i << 1) + 1].val);
}

// 建立线段树
void build(int l, int r, int i) {
    segTree[i].l = l, segTree[i].r = r, segTree[i].lazy = 0, segTree[i].len = r - l + 1;
    if (l == r) {
        segTree[i].val = w;
        return;
    }
    int mid = ((l + r) >> 1);
    build(l, mid, i << 1);
    build(mid + 1, r, (i << 1) + 1);
    pushUp(i);
}

int queryAndUpdate(int width, int i) {
    if (segTree[i].val < width) return -1;
    int l = segTree[i].l;
    int r = segTree[i].r;
    // 到达叶子节点
    if (l == r) {
        segTree[i].val -= width;
        return l;
    }
    int ans;
    if (segTree[i << 1].val >= width) {
        ans = queryAndUpdate(width, i << 1);
    } else {
        ans = queryAndUpdate(width, (i << 1) + 1);
    }
    pushUp(i);
    return ans;
}


int main() {
    int width;
    //======================================
    while (cin >> h) {
        cin >> w >> n;
        build(1, min(n, h), 1);
        for (int i = 0; i < n; i++) {
            scanf("%d", &width);
            printf("%d\n", queryAndUpdate(width, 1));
        }
    }
    return 0;
}
