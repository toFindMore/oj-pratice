//
// Created by 周健 on 3/26/21.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 1e6 + 5;

struct segTree {
    // cnt表示[l,r]位置上的长度
    int l, r, sum;
    long long val;
} segTree[SIZE * 6];

struct line {
    int x, y1, y2, state;

} li[SIZE << 1];

int cmp(line x1, line x2) {
    return x1.x < x2.x;
}

vector<int> yVec;

int n;

int ls(int i) {
    return i << 1;
}

int rs(int i) {
    return i << 1 | 1;
}

int getPid(int num) {
    return lower_bound(yVec.begin(), yVec.end(), num) - yVec.begin();
}

void pushUp(int pos) {
    // 被完全覆盖
    if (segTree[pos].sum > 0) {
        segTree[pos].val = yVec[segTree[pos].r-1] - yVec[segTree[pos].l-1];
    } else segTree[pos].val = segTree[ls(pos)].val + segTree[rs(pos)].val;
}

void build(int l, int r, int pos) {
    segTree[pos].l = l, segTree[pos].r = r, segTree[pos].val = 0, segTree[pos].sum = 0;
    if (l + 1 >= r) return;
    int mid = (l + r) >> 1;
    build(l, mid, ls(pos));
    build(mid, r, rs(pos));
}

void modify(int l, int r, int x, int pos) {
    int lc = segTree[pos].l;
    int rc = segTree[pos].r;
    if (l <= lc && rc <= r) {
        segTree[pos].sum += x;
        pushUp(pos);
        return;
    }
    if (l < segTree[ls(pos)].r) modify(l, r, x, ls(pos));
    if (r > segTree[rs(pos)].l) modify(l, r, x, rs(pos));
    pushUp(pos);
}

int main() {
    cin >> n;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        yVec.push_back(y1);
        yVec.push_back(y2);
        li[i].x = x1, li[i].y1 = y1, li[i].y2 = y2, li[i].state = 1;
        li[i + n].x = x2, li[i + n].y1 = y1, li[i + n].y2 = y2, li[i + n].state = -1;
    }
    sort(yVec.begin(), yVec.end());
    sort(li + 1, li + (n << 1) + 1, cmp);
    // 离散化
    auto lastIndex = unique(yVec.begin(), yVec.end());
    yVec.erase(lastIndex, yVec.end());
    unsigned long long ans = 0;
    build(1, n << 1, 1);
    for (int i = 1; i <= (n << 1); i++) {
        ans += segTree[1].val * (li[i].x - li[i - 1].x);
        modify(getPid(li[i].y1) + 1, getPid(li[i].y2) + 1, li[i].state, 1);
    }
    cout << ans << endl;
    return 0;
}