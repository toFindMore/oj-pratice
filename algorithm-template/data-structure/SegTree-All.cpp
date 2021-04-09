
const int SIZE = 2e5 + 5;

struct node {
    // val 维护相应的值
    int l, r, val;
    // lazy 标识下面每个值需要加的数
    int lazy, len;
} segTree[SIZE * 4];

int arr[SIZE];

// 更新父节点i
void pushUp(int i) {
    segTree[i].val = segTree[i << 1].val + segTree[(i << 1) + 1].val;
}

// 更新左右孩子
void pushDown(int i) {
    // 更新左孩子
    segTree[i << 1].lazy += segTree[i].lazy;
    segTree[i << 1].val += segTree[i << 1].len * segTree[i].lazy;
    // 更细右孩子
    segTree[(i << 1) + 1].lazy += segTree[i].lazy;
    segTree[(i << 1) + 1].val += segTree[(i << 1) + 1].len * segTree[i].lazy;
    // 父节点清零
    segTree[i].lazy = 0;
}

// 建立线段树
void build(int l, int r, int i) {
    segTree[i].l = l, segTree[i].r = r, segTree[i].lazy = 0, segTree[i].len = r - l + 1;
    if (l == r) {
        segTree[i].val = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, (i << 1) + 1);
    pushUp(i);
}

// 单节点更新 i表示数组下标 x表示对应点的arr的实际位置
// 没必要使用lazyTag
void update(int x, int addVal, int i) {
    int l = segTree[i].l;
    int r = segTree[i].r;
    // 到达叶子节点
    if (l == r && l == x) {
        segTree[i].val += addVal;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(x, addVal, i << 1);
    else update(x, addVal, (i << 1) + 1);
    pushUp(i);
}

// 区间更新
void update(int l, int r, int addVal, int i) {
    int lc = segTree[i].l;
    int rc = segTree[i].r;
    if (lc == l && rc == r) {
        segTree[i].lazy += addVal;
        segTree[i].val += segTree[i].len * addVal;
        return;
    }
    if (segTree[i].lazy) pushDown(i);
    int mid = (lc + rc) >> 1;
    if (r <= mid) update(l, r, addVal, i << 1);
    else if (l > mid) update(l, r, addVal, (i << 1) + 1);
    else update(l, mid, addVal, i << 1), update(mid + 1, r, addVal, (i << 1) + 1);
    pushUp(i);
}

// 区间查询
int query(int l, int r, int i) {
    if (segTree[i].l == l && segTree[i].r == r) {
        return segTree[i].val;
    }
    if (segTree[i].lazy) pushDown(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid) return query(l, r, i << 1);
    else if (l > mid) return query(l, r, (i << 1) + 1);
    else return query(l, mid, i << 1) + query(mid + 1, r, (i << 1) + 1);
}