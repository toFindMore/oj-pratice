//
// Created by 周健 on 2019-12-09.
//
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int T;
    string a, b;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        cin >> a >> b;
        printf("Case %d:\n", k);
        cout << a << " + " << b << " = ";
        int sizeA = a.size();
        int sizeB = b.size();
        string zeroString = "";
        for (int i = 0; i < abs(sizeA - sizeB); i++) {
            zeroString = zeroString + "0";
        }
        if (sizeA > sizeB) {
            b = zeroString + b;
        } else {
            a = zeroString + a;
        }
        // 借位
        int borrow = 0;
        string res;
        for (int i = (sizeA > sizeB ? sizeA : sizeB) - 1; i >= 0; i--) {
            int intA = a[i] - '0';
            int intB = b[i] - '0';
            int intSum = intA + intB + borrow;
            if (intSum >= 10) {
                res += (intSum - 10) + '0';
                borrow = 1;
            } else {
                res += intSum + '0';
                borrow = 0;
            }
        }
        if (borrow == 1) {
            res += "1";
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
        if (k != T) {
            cout << endl;
        }
    }
    return 0;
}
