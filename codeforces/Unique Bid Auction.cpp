//
// Created by 周健 on 11/24/20.
//
#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    int caseNum, n, tmp;
    cin >> caseNum;
    priority_queue<int, vector<int>, greater<int> > q;
    set<int> s1, s2;
    map<int, int> num2Pos;
    while (caseNum--) {
        s1.clear();
        s2.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            num2Pos[tmp] = i+1;
            if (s2.count(tmp)) {
                continue;
            } else if (s1.count(tmp)) {
                s2.insert(tmp);
                s1.erase(tmp);
            } else {
                s1.insert(tmp);
            }
        }
        if (s1.empty()) {
            cout << "-1" << endl;
            continue;
        }
        int minNum = 999999;
        for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
            minNum = min(*it, minNum);
        }
        cout << num2Pos[minNum] << endl;
    }
    return 0;
}
