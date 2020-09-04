//
// Created by 周健 on 2020-08-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {


public:

#define MAX 100000+5

    int father[MAX]; //父节点
    int people[MAX]; //每个集合中的元素个数
    int rank[MAX]; //秩
    set<int> ff;

    int find(int x) {
        if (x != father[x])
            father[x] = find(father[x]);

        return father[x];
    }

    //合并并返回合并后的祖先序号
    void Union(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y]) {
            father[y] = x;

            //两者祖先相同时，实际没发生合并，只考虑祖先不同的情况
            if (x != y) {
                people[x] += people[y];
                ff.erase(y);
            }

            if (rank[x] == rank[y]) //树高相同时让父节点的树高值加一
                rank[y] += 1;
        } else {
            father[x] = y;

            //两者祖先相同时，实际没发生合并，只考虑祖先不同的情况
            if (x != y) {
                ff.erase(x);
                people[y] += people[x];
            }

            if (rank[x] == rank[y]) //树高相同时让父节点的树高值加一
                rank[y] += 1;
        }
    }

    int findLatestStep(vector<int> &arr, int m) {
        int res = -1;
        int isVis[MAX];
        memset(isVis, 0, sizeof(isVis));
        for (int i = 1; i <= arr.size(); i++) {
            father[i] = i;
            people[i] = 1;
            rank[i] = 0;
            ff.insert(i);
        }

        for (int i = 0; i < arr.size(); i++) {
            int index = arr[i];
            if (index >= 2 && isVis[index - 1] == 1) {
                Union(index, index - 1);
            }
            if (index < arr.size() && isVis[index + 1] == 1) {
                Union(index, index + 1);
            }
            isVis[index] = 1;

            for (set<int>::iterator it = ff.begin(); it != ff.end(); it++) {
                if (isVis[*it] != 0 && people[*it] == m) {
                    res = i + 1;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vv;
    vv.push_back(4);
    vv.push_back(3);
    vv.push_back(2);
    vv.push_back(1);
//    vv.push_back(4);
//    vv.push_back(0);
//    vv.push_back(0);
//    vv.push_back(1);
//    vv.push_back(0);
    cout << s.findLatestStep(vv, 1) << endl;
    for (int i = 0; i <= 5; i++) {
        cout << s.father[i] << " ";
    }

    return 0;
}
