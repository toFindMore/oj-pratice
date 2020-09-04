//
// Created by 周健 on 2020-08-09.
//
#include <iostream>
#include <stack>

using namespace std;

class Solution {

public:
    string makeGood(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && ( stk.top() - 'a' == s[i] - 'A' || stk.top() - 'A' == s[i] - 'a' )) {
                stk.pop();
                continue;
            }
            stk.push(s[i]);
        }
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    cout << s.makeGood("leEeetcode");
    return 0;
}