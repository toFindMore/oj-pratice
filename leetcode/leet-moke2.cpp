//
// Created by 周健 on 2020-09-05.
//
#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int i = 2; i <= n; i++) {
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
        }
        return a + e + i + o + u;
    }
};