//
// Created by 周健 on 11/29/20.
//
#include <iostream>

using namespace std;

int main() {
    long long caseNum;
    cin >> caseNum;
    long long n, m, r, c;
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    while (caseNum--) {
        cin >> n >> m >> r >> c;
        x1 = 1, y1 = 1;
        x2 = n, y2 = 1;
        x3 = 1, y3 = m;
        x4 = n, y4 = m;
        long long sum = r + c;
        cout << max(abs(sum - x2 - y2), max(abs(sum - x1 - y1), max(abs(sum - x3 - y3), abs(sum - x4 - y4)))) << endl;
    }
    return 0;
}
