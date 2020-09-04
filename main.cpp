//
// Created by 周健 on 2019-08-02.
//
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <vector>

using namespace std;

long long a[11][11];


int main()
{
    int n;
    scanf("%d",&n);
    if(n == 1) {
        printf("1\n");
        return 0;
    }
    // left : tag = 1;
    // right : tag = 2;
    // up : tag = 3;
    // down : tag = 4;
    int x , y, tag;
    if(n % 2 == 1) {
        x = n/2;
        y = n/2;
        tag = 1;
    } else {
        x = n/2;
        y = n/2-1;
        tag = 2;
    }

    a[x][y] = 1;
    long long prepre = 0,pre = 1;

    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = -1;
        }
    }

    a[x][y] = 1;

    while(true) {
        if(tag == 1) {
            y -= 1;
        } else if(tag == 2) {
            y += 1;
        } else if(tag == 3) {
            x -= 1;
        } else {
            x += 1;
        }
        a[x][y] = pre + prepre;
        if(x == 0 && y == 0) {
            break;
        }
        prepre = pre;
        pre = a[x][y];

        if(tag == 1 && a[x+1][y] == -1) {
            tag = 4;
        } else if(tag == 2 && a[x-1][y] == -1) {
            tag = 3;
        } else if(tag == 3 && a[x][y-1] == -1) {
            tag = 1;
        } else if(tag == 4 && a[x][y+1] == -1) {
            tag = 2;
        }
    }


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%lld",a[i][j]);
            if(j != n-1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}