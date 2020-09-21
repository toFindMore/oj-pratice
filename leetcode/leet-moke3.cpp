//
// Created by 周健 on 2020-09-05.
//
#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
    struct Info {
        int cost;
        char value;
        Info(int _cost, char _value) {
            cost = _cost;
            value = _value;
        }
    };
public:
    int minCost(string s, vector<int> &cost) {
        stack<Info> stack;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if(stack.empty()) {
                stack.push(Info(cost[i], s[i]));
            } else {
                if(s[i] == stack.top().value) {
                    if(cost[i] < stack.top().cost) {
                        res += cost[i];
                    } else {
                        res += stack.top().cost;
                        stack.pop();
                        stack.push(Info(cost[i], s[i]));
                    }
                } else {
                    stack.push(Info(cost[i], s[i]));
                }
            }
        }
        return res;
    }
};