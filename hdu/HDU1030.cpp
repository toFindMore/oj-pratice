//
// Created by 周健 on 2020-02-04.
//
#include <stdio.h>
#include <math.h>

struct BlockInfo {
    // 层 | 左层 | 右层
    int level, leftLevel, rightLevel;
};

BlockInfo cal(int n) {
    BlockInfo blockInfo;
    int level = ceil(sqrt(n));
    int startNum = (level - 1) * (level - 1) + 1;
    int endNum = level * level;
    blockInfo.level = level;
    blockInfo.leftLevel = (n - startNum) / 2 + 1;
    blockInfo.rightLevel = (endNum - n) / 2 + 1;
    return blockInfo;
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        BlockInfo infoM = cal(m);
        BlockInfo infoN = cal(n);
        int res = (int) fabs(infoM.level - infoN.level) + (int) fabs(infoM.rightLevel - infoN.rightLevel) +
                  (int) fabs(infoM.leftLevel - infoN.leftLevel);
        printf("%d\n", res);
    }
    return 0;
}