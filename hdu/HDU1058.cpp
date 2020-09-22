//
// Humble Numbers
// Created by 周健 on 2020-09-21.
//
#include <stdio.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

long long num[6000];

long long min(long long x, long long y) {
    return x > y ? y : x;
}

void init() {
    num[1] = 1;
    int cnt = 1;
    map<long long, long long> mm;
    mm[2] = 1, mm[3] = 1, mm[5] = 1, mm[7] = 1;
    while (cnt <= 5842) {
        long long minNum = min(num[mm[2]] * 2, min(num[mm[3]] * 3, min(num[mm[5]] * 5, num[mm[7]] * 7)));
        if (num[mm[2]] * 2 == minNum) mm[2]++;
        if (num[mm[3]] * 3 == minNum) mm[3]++;
        if (num[mm[5]] * 5 == minNum) mm[5]++;
        if (num[mm[7]] * 7 == minNum) mm[7]++;
        num[++cnt] = minNum;
    }
}

int main() {
    int n;
    init();
    while (cin >> n, n != 0) {
        cout << "The " << n;
        if (n % 10 == 1 && n % 100 != 11) {
            cout << "st";
        } else if (n % 10 == 2 && n % 100 != 12) {
            cout << "nd";
        } else if (n % 10 == 3 && n % 100 != 13) {
            cout << "rd";
        } else {
            cout << "th";
        }
        cout << " humble number is " << num[n] << "." << endl;
    }
    return 0;
}
