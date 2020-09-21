//
// Created by 周健 on 2020-09-05.
//
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        set<char> strSet;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') {
                char pre, next;
                if (i - 1 < 0) {
                    pre = '1';
                } else {
                    pre = res[i - 1];
                }
                if (i + 1 > s.size()) {
                    next = '1';
                } else {
                    if (s[i + 1] == '?') {
                        next = '1';
                    } else {
                        next = s[i + 1];
                    }
                }
                int j;
                for (j = 0; j < 26; j++) {
                    if (j + 'a' != pre && j + 'a' != next) {
                        break;
                    }
                }
                res += ('a' + j);
            } else {
                res += s[i];
            }
            cout << res << endl;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    s.modifyString("j?qg??b");
    return 0;
}