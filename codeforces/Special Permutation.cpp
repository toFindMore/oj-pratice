//
// Created by 周健 on 11/24/20.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int caseNum, num;
    cin >> caseNum;
    while (caseNum--) {
        cin >> num;
        if (num & 1) {
            int k = num / 2 + 1;
            for (int i = k; i <= num - 1; i++) cout << i << " ";
            cout << num << " ";
            for (int i = 1; i < k; i++) cout << i << " ";
        } else {
            for (int i = num; i >= 1; i--) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
