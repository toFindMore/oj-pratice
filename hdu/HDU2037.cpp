//
// Created by 周健 on 2019-08-02.
//
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Pos {
    int start_time;
    int end_time;
    int val;

    Pos() {
        val = -1;
    }
};

bool cmp(Pos p1, Pos p2) {
    if(p1.end_time == p2.end_time) {
        return p1.start_time > p2.start_time;
    }
    if (p1.end_time < p2.end_time) return true;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n != 0) {
        Pos pos[105];
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &pos[i].start_time, &pos[i].end_time);
        }
        sort(pos, pos + n, cmp);
        int end = pos[0].end_time, count = 1;
        for (int i = 1; i < n; i++)
            if (pos[i].start_time >= end) {
                end = pos[i].end_time;
                count++;
            }
        cout << count << endl;
        scanf("%d", &n);
    }
    return 0;
}

