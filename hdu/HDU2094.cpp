//
// Created by 周健 on 2019-08-02.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        vector<pair<string, string> > vv;
        map<string, int> in;
        map<string, set<string> > mp;
        queue<string> del;
        for (int i = 0; i < n; i++) {
            string m1, m2;
            cin >> m1 >> m2;
            pair<string, string> p(m1, m2);
            vv.push_back(p);
            mp[m1].insert(m2);
            in[m2] += 1;
        }

        for (map<string, int>::iterator it = in.begin(); it != in.end(); it++) {
            if (in[it->first] == 0) {
                del.push(it->first);
            }
        }

        int cnt = 0;
        while (!del.empty()) {
            string id = del.front();
            del.pop();
            set<string> member = mp[id];
            for (set<string>::iterator it = member.begin(); it != member.end(); it++) {
                in[*it] -= 1;
                if(in[*it] == 0) {
                    del.push(*it);
                }
            }
            ++cnt;
        }
        if(cnt == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
