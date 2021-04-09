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

int main() {
    ll t = lcm(4, 6);
    cout << t ;
    return 0;
}
