//
// Created by 周健 on 3/28/21.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>

using namespace std;

typedef double db;
typedef long long ll;

const db EPS = 1e-6;
const ll MOD = 1e9 + 7;

// 获取最大公倍数
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 获取最小公倍数
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

//快速乘法，计算a*b %p, a>0,b>0
ll qmuti(ll a, ll b) {
    if (b <= 0)return 0;
    ll r = qmuti(a, b / 2);
    r = (r + r) % MOD;
    if (b % 2)r = (r + a) % MOD;
    return r;
}

//快速幂，计算a^b %MOD, b>0
ll qpow(ll a, ll b) {
    if (b <= 0)return 1;
    ll r = qpow(a, b / 2);
    r = qmuti(r, r);
    if (b % 2) r = qmuti(r, a);
    return r;
}


int lowbit(int x) { return x & (-x); }

const int SIZE = 50005;

int n, T, bit[SIZE];

//void update(int x, int v) {
//    while (x <= n) {
//        bit[x] += v;
//        x += lowbit(x);
//    }
//}
//
//int getSum(int x) {
//    int ans = 0;
//    while (x > 0) {
//        ans += bit[x];
//        x -= lowbit(x);
//    }
//    return ans;
//}
//
//int query(int l, int r) {
//    return getSum(r) - getSum(l - 1);
//}
//
//int main() {
//    cin >> T;
//    string sign;
//    int tmp, op1, op2;
//    for (int i = 1; i <= T; i++) {
//        printf("Case %d:\n", i);
//        fill(bit, bit + SIZE, 0);
//        cin >> n;
//        for (int j = 1; j <= n; j++) scanf("%d", &tmp), update(j, tmp);
//        while ((cin >> sign) && sign != "End") {
//            scanf("%d%d", &op1, &op2);
//            if (sign == "Query") {
//                printf("%d\n", query(op1, op2));
//            } else if (sign == "Add") {
//                update(op1, op2);
//            } else if (sign == "Sub") {
//                update(op1, -1 * op2);
//            }
//        }
//    }
//    return 0;
//}


struct segTree {
    int l, r, sum;
} segTree[(SIZE << 2) + 1];

int arr[SIZE];

int ls(int x) {
    return x << 1;
}

int rs(int x) {
    return x << 1 | 1;
}

void pushUp(int x) {
    segTree[x].sum = segTree[ls(x)].sum + segTree[rs(x)].sum;
}

void build(int i, int l, int r) {
    segTree[i].l = l, segTree[i].r = r, segTree[i].sum = 0;
    if (l == r) {
        segTree[i].sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(i), l, mid);
    build(rs(i), mid + 1, r);
    pushUp(i);
}

int query(int l, int r, int i) {
    if (l == segTree[i].l && r == segTree[i].r) return segTree[i].sum;
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid) return query(l, r, ls(i));
    if (l > mid) return query(l, r, rs(i));
    return query(l, mid, ls(i)) + query(mid + 1, r, rs(i));
}

void modify(int i, int idx, int val) {
    if (segTree[i].l == segTree[i].r) {
        segTree[i].sum += val;
        return;
    }
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (idx <= mid) modify(ls(i), idx, val);
    if (idx > mid) modify(rs(i), idx, val);
    pushUp(i);
}

int main() {
    cin >> T;
    string sign;
    int tmp, op1, op2;
    for (int i = 1; i <= T; i++) {
        printf("Case %d:\n", i);
        fill(bit, bit + SIZE, 0);
        cin >> n;
        for (int j = 1; j <= n; j++) scanf("%d", &arr[j]);
        build(1, 1, n);
        while ((cin >> sign) && sign != "End") {
            scanf("%d%d", &op1, &op2);
            if (sign == "Query") {
                printf("%d\n", query(op1, op2, 1));
            } else if (sign == "Add") {
                modify(1, op1, op2);
            } else if (sign == "Sub") {
                modify(1, op1, -1 * op2);
            }
        }
    }
    return 0;
}