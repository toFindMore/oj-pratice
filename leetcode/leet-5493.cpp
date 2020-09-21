//
// Created by 周健 on 2020-09-06.
//
#include <stdio.h>

int min(int x, int y) {
    return x > y ? y : x;
}

int findLengthOfShortestSubarray(int *arr, int arrSize) {
    int pos1 = 0, pos2 = arrSize - 1;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < arr[pos1]) {
            break;
        }
        pos1 = i;
    }
    for (int i = arrSize - 2; i >= 0; i--) {
        if (arr[i] > arr[pos2]) {
            break;
        }
        pos2 = i;
    }
    if (pos2 <= pos1) {
        return 0;
    }
    int left = 0, right = pos2;
    int res = arrSize - pos1 - 1;
    res = min(res, pos2);
    while (left <= pos1) {
        if (right >= arrSize) {
            break;
        }
        while (arr[left] > arr[right]) {
            right++;
            if (right >= arrSize) {
                break;
            }
        }
        res = min(res, right - left - 1);
        left++;
    }
    return res;
}

int main() {
    int a[] = {5, 4, 3, 2, 1};
    printf("%d\n", findLengthOfShortestSubarray(a, 5));
    return 0;
}