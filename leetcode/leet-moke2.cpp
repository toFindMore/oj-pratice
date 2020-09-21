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
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> num1Map, num2Map;
        for (int i = 0; i < nums1.size(); i++) {
            if (num1Map.count(nums1[i])) {
                num1Map[nums1[i]] = num1Map[nums1[i]] + 1;
            } else {
                num1Map[nums1[i]] = 1;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (num2Map.count(nums2[i])) {
                num2Map[nums2[i]] = num2Map[nums2[i]] + 1;
            } else {
                num2Map[nums2[i]] = 1;
            }

        }

        int res = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                long long num1 = (long long) nums1[i] * nums1[j];
                long long tmp = sqrt(num1);
                if (tmp * tmp == num1 && num2Map.count(tmp)) {
                    res += num2Map[tmp];
                }
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                long long num1 = (long long) nums2[i] * nums2[j];
                long long tmp = sqrt(num1);
                if (tmp * tmp == num1 && num1Map.count(tmp)) {
                    res += num1Map[tmp];
                }
            }
        }
        return res;
    }
};