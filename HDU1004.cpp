//
// Created by 周健 on 2019-12-11.
//
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    map<string, int> mm;
    string ss;
    while (scanf("%d", &n) && n != 0) {
        mm.clear();
        for (int i = 0; i < n; ++i) {
            cin >> ss;
            if (mm.count(ss) == 0) {
                mm[ss] = 0;
            }
            mm[ss] += 1;
        }
        int maxValue = -1;
        string res;
        for (map<string, int>::iterator it = mm.begin(); it != mm.end(); it++) {
            if(it->second > maxValue) {
                maxValue = it->second;
                res= it->first;
            }
        }
        cout << res << endl;
    }
    return 0;
}
