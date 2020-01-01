//
// Created by 周健 on 2019-09-03.
//
#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

int main() {
    string N;
    int K;
    cin >> N >> K;
    int k = K;
    int len = N.size();
    Node* header = new Node(-1);
    Node* p = header;
    for (int i = 0; i < len; i++) {
        Node* nn = new Node(N[i]-'0');
        p->next = nn;
        p = nn;
    }
    p = header;
    for (Node *iNode = header->next; iNode != NULL; iNode = iNode->next) {
        if (iNode->next == NULL || K == 0) {
            break;
        }
        Node* tNode = iNode->next;
        if (iNode->value > tNode->value) {
            p->next = tNode;
            // 初始化
            p = header;
            iNode = header;
            --K;
        } else {
            p = p->next;
        }
    }
    int cnt = 0;
    int tt = len - k;
    bool flag = false;
    bool flag1 = false;
    for (Node *iNode = header->next; iNode != NULL; iNode = iNode->next) {
        if (cnt == tt) {
            break;
        }
        if(flag == false && iNode->value == 0) {
            flag = true;
            continue;
        }
        cout << iNode->value;
        flag1 = true;
        cnt++;
    }
    if(flag1 == false) {
        cout << "0";
    }
    return 0;

}