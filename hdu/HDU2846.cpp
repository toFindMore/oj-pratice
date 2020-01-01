//
// Created by 周健 on 2019-07-29.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <queue>

using namespace std;

struct Node {
    Node *node[27];
    Node *failNode;
};

void insert(Node *root, char *str, int t) {
    int k = 0;
    Node *p = root;
    while (str[k] != '\0') {
        int id = str[k] - 'a';
        if (p->node[id] == NULL) {
            p->node[id] = new Node;
        }
        p = p->node[id];
        ++k;
    }
}

bool search(Node *root, char *str) {
    int k = 0;
    Node *p = root;

    while (str[k] != '\0') {
        int id = str[k] - 'a';
        if (p->node[id] == NULL) {
            return false;
        }
        p = p->node[id];
        ++k;
    }
    return true;
}

queue<Node *> QQ;

void init(Node *root) {
    for (int i = 0; i < 26; i++) {
        Node *n = root->node[i];
        if (n == NULL) continue;
        n->failNode = root;
        QQ.push(n);
    }
}

void setFail(Node *root) {
    init(root);
    while (!QQ.empty()) {
        Node *n = QQ.front();
        // nn 为父节点的信息
        Node *nn = n->failNode;
        for (int i = 0; i < 26; i++) {
            Node *in = n->node[i];
            if (in == NULL) continue;
            if (nn->node[i] == NULL) {
                in->failNode = root;
            } else {
                in->failNode = nn->node[i];
            }
            QQ.push(in);
        }
        QQ.pop();
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    Node *root = new Node;
    for (int i = 0; i < n; i++) {
        char ch[35];
        scanf("%s", ch);
        int len = strlen(ch);
        for (int j = 0; j < len; j++) {
            insert(root, ch + j, i);
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char ch[35];
        scanf("%s", ch);
        printf("%d\n", search(root, ch));
    }

    return 0;
}
