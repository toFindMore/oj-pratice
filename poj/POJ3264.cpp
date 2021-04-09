//
// Created by 周健 on 3/25/21.
//
#include <algorithm>
#include <iostream>

using namespace std;

const int SIZE = 2e5 + 5;

struct node {
    // val 维护相应的值
    int l, r, maxNum, minNum;
} segTree[SIZE * 4];

int arr[SIZE];

// 更新父节点i
void pushUp(int i, node segTree[]) {
    segTree[i].maxNum = max(segTree[i << 1].maxNum, segTree[(i << 1) + 1].maxNum);
    segTree[i].minNum = min(segTree[i << 1].minNum, segTree[(i << 1) + 1].minNum);
}

// 建立线段树
void build(int l, int r, int i) {
    segTree[i].l = l, segTree[i].r = r;
    if (l == r) {
        segTree[i].maxNum = segTree[i].minNum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, (i << 1) + 1);
    pushUp(i, segTree);
}

// 区间查询
int queryMin(int l, int r, int i) {
    if (l == segTree[i].l && r == segTree[i].r) {
        return segTree[i].minNum;
    }
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid) {
        return queryMin(l, r, i << 1);
    } else if (l > mid) {
        return queryMin(l, r, (i << 1) + 1);
    } else {
        return min(queryMin(l, mid, i << 1), queryMin(mid + 1, r, (i << 1) + 1));
    }
}

int queryMax(int l, int r, int i) {
    if (l == segTree[i].l && r == segTree[i].r) {
        return segTree[i].maxNum;
    }
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid) {
        return queryMax(l, r, i << 1);
    } else if (l > mid) {
        return queryMax(l, r, (i << 1) + 1);
    } else {
        return max(queryMax(l, mid, i << 1), queryMax(mid + 1, r, (i << 1) + 1));
    }
}

int main() {
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    build(1, n, 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        cout << queryMax(l, r, 1) - queryMin(l, r, 1) << endl;
    }
    return 0;
}
