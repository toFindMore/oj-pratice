#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 110010;
char A[MAXN * 2];
int B[MAXN * 2];

void Manacher(char s[], int len) {
    int l = 0;
    A[l++] = '$'; // 0下标存储为其他字符
    A[l++] = '#';
    for (int i = 0; i < len; i++) {
        A[l++] = s[i];
        A[l++] = '#';
    }
    A[l] = 0;
    int mx = 0;
    int id = 0;
    for (int i = 0; i < l; i++) {
        B[i] = mx > i ? std::min(B[2 * id - i], mx - i) : 1;
        while (A[i + B[i]] == A[i - B[i]]) {
            B[i]++;
        }
        if (i + B[i] > mx) {
            mx = i + B[i];
            id = i;
        }
    }
}