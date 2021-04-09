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


int n, m;
const int SIZE = 3e5 + 5;

struct Node {
    int l, r;
    int val, key;
    int size;
} fhq[SIZE];
int cnt, root;

#include <random>

std::mt19937 rnd(233);

inline int newnode(int val) {
    fhq[++cnt].val = val;
    fhq[cnt].key = rnd();
    fhq[cnt].size = 1;
    return cnt;
}

inline void update(int now) {
    fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
}

void split(int now, int siz, int &x, int &y) {
    if (!now) x = y = 0;
    else {
        if (fhq[fhq[now].l].size < siz) {
            x = now;
            split(fhq[now].r, siz - fhq[fhq[now].l].size - 1, fhq[now].r, y);
        } else {
            y = now;
            split(fhq[now].l, siz, x, fhq[now].l);
        }
        update(now);
    }
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (fhq[x].key < fhq[y].key) {
        fhq[x].r = merge(fhq[x].r, y);
        update(x);
        return x;
    } else {
        fhq[y].l = merge(x, fhq[y].l);
        update(y);
        return y;
    }
}

int l, r, t;

void ldr(int now) {
//    if (t == 0) return;
    if (!now) return;
    ldr(fhq[now].l);
    t--;
    printf("%d\n", fhq[now].val);
    ldr(fhq[now].r);
}


int x, y, z;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &t), root = merge(root, newnode(t));
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &l, &r, &t);
        split(root, l - 1, x, z);
        split(z, r - l + 1, y, z);
        ldr(y);
        root = merge(merge(x, y), z);
    }
    return 0;
}
