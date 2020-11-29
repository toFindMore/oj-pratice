//
// Created by 周健 on 11/24/20.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int caseNum, n, tmp, prev, start, end;
    cin >> caseNum;
    vector<int> vv;
    map<int, int> key2Num;
    while (caseNum--) {
        scanf("%d", &n);
        scanf("%d", &tmp);
        key2Num.clear();
        vv.clear();
        key2Num[tmp]++;
        prev = tmp;
        start = prev;
        for (int i = 1; i < n; i++) {
            scanf("%d", &tmp);
            if (tmp == prev) continue;
            key2Num[tmp]++;
            prev = tmp;
        }
        end = prev;
        if (key2Num.size() == 1) {
            cout << "0" << endl;
            continue;
        }
        if (start == end) {
            if (key2Num[start] == 2) {
                cout << "1" << endl;
                continue;
            }
            key2Num[start] -= 2;
        } else {
            if (key2Num[start] == 1) {
                cout << "1" << endl;
                continue;
            } else {
                key2Num[start]--;
            }

            if (key2Num[end] == 1) {
                cout << "1" << endl;
                continue;
            } else {
                key2Num[end]--;
            }
        }

        int minNum = 9999999;
        for (map<int, int>::iterator it = key2Num.begin(); it != key2Num.end(); it++) {
            minNum = min(it->second,minNum);
        }
        cout << minNum + 1 << endl;
    }
    return 0;
}
