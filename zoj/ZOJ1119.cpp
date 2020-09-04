//
// Created by 周健 on 2020-09-04.
//
#include <stdio.h>

const int SIZE = 1005;

struct Node {
    int v;
    Node *next;

    Node(int _v) {
        v = _v;
    }

    Node() {}
};

Node nodeArr[SIZE];
int dfn[SIZE];
int low[SIZE];
int visit[SIZE];
int timestamp = 0;
int res[SIZE];
int cutNum[SIZE];
int N = -1;

int min(int x, int y) {
    return x > y ? y : x;
}

int max(int x, int y) {
    return x > y ? x : y;
}

void init() {
    for (int i = 0; i < SIZE; i++) {
        nodeArr[i].next = NULL;
        visit[i] = 0;
        res[i] = 0;
        cutNum[i] = 0;
    }
    N = -1;
    timestamp = 0;
}


void tarjan(int cur, int father) {
    low[cur] = ++timestamp;
    dfn[cur] = timestamp;
    visit[cur] = 1;
    Node *node = nodeArr[cur].next;
    while (node != NULL) {
        if (visit[node->v] == 0) {
            tarjan(node->v, cur);
            low[cur] = min(low[cur], low[node->v]);
            if (low[node->v] >= dfn[cur]) {
                cutNum[cur]++;
            }
        } else if (node->v != father) {
            low[cur] = min(low[cur], low[node->v]);
        }

        node = node->next;
    }
}

int main() {
    int flag1 = false;
    init();
    int cnt = 0;
    while (true) {
        int num1, num2;
        scanf("%d", &num1);
        N = max(N, num1);
        if (num1 == 0 && !flag1) {
            break;
        }
        if (num1 == 0 && flag1) {
            // main work
            if(cnt) {
                printf("\n");
            }
            printf("Network #%d\n", ++cnt);
            tarjan(1, 1);
            int flag = false;
            for (int i = 1; i <= N; i++) {
                if (i == 1 && cutNum[1] > 1) {
                    printf("  SPF node %d leaves %d subnets\n", i, cutNum[1]);
                    flag = true;
                } else if (i != 1 && cutNum[i] > 0) {
                    printf("  SPF node %d leaves %d subnets\n", i, cutNum[i] + 1);
                    flag = true;
                }
            }
            if (!flag) {
                printf("  No SPF nodes\n");
            }
            flag1 = false;
            init();
            continue;
        } else {
            flag1 = true;
        }
        scanf("%d", &num2);
        N = max(N, num2);
        Node *node1 = new Node(num1);
        Node *node2 = new Node(num2);

        // 头插法
        Node *tmp = nodeArr[num1].next;
        nodeArr[num1].next = node2;
        node2->next = tmp;

        tmp = nodeArr[num2].next;
        nodeArr[num2].next = node1;
        node1->next = tmp;
    }
    return 0;
}
