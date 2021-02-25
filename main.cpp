#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 100005;

int origin[maxn], bit[maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int i, int x) {
    while (i < maxn) {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getSum(int i) {
    int sum = 0;
    while (i) {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        fill(bit, bit + maxn, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", origin + i);
            add(origin[i], 1);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = getSum(origin[i] - 1);
            ans += tmp * (n - 1 - tmp);
        }
        cout << ans << endl;
    }
    return 0;
}