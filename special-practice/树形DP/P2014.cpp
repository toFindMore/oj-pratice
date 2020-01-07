//
// Created by 周健 on 2020-01-06.
//
#include <stdio.h>

int tot;

// 利用链式前向星进行数据存储
int head[301];

int max(int a, int b) {
    return a > b ? a : b;
}

struct Node {
    int to;
    int next;
} edge[601];

int dp[301][301];

int n, m;

void add(int from, int to) {
    edge[++tot].next = head[from];
    edge[tot].to = to;
    head[from] = tot;
}

void dfs(int now) {
    for (int k = head[now]; k; k = edge[k].next) {
        int to = edge[k].to;
        dfs(to);
        // 这里包括虚拟节点
        for (int i = m + 1; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                dp[now][i] = max(dp[now][i], dp[to][j] + dp[now][i - j]);
                // 以下情况会导致覆盖
                // dp[now][i] = max(dp[now][i], dp[now][j] + dp[to][i - j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int v, value;
        scanf("%d%d", &v, &value);
        dp[i][1] = value;
        add(v, i);
    }
    dfs(0);
    // 共有m+1个，因为虚拟节点也算一个
    printf("%d\n", dp[0][m + 1]);
//    for(int i=0;i<20;i++) {
//        printf("%d %d\n",edge[i].to,edge[i].next);
//    }
    return 0;
}

//#include<iostream>
//#include<cstdio>
//#define maxn 1000
//using namespace std;
//int n,m,f[maxn][maxn],head[maxn],cnt;
//struct edge
//{
//    int to,pre;
//}e[maxn];
//inline int in()
//{
//    char a=getchar();
//    while(a<'0'||a>'9')
//    {
//        a=getchar();
//    }
//    int t=0;
//    while(a>='0'&&a<='9')
//    {
//        t=(t<<1)+(t<<3)+a-'0';
//        a=getchar();
//    }
//    return t;
//}
//void add(int from,int to)
//{
//    e[++cnt].pre=head[from];
//    e[cnt].to=to;
//    head[from]=cnt;
//}
//void dp(int now)
//{
////    f[now][0]=0;
//    for(int i=head[now];i;i=e[i].pre)
//    {
//        int go=e[i].to;
//        dp(go);
//        for(int j=m+1;j>=1;j--)
//        {
//            for(int k=0;k<j;k++)
//            {
//                f[now][j]=max(f[now][j],f[go][k]+f[now][j-k]);
//            }
//        }
//    }
//}
//int main()
//{
//    n=in(),m=in();
//    for(int i=1;i<=n;i++)
//    {
//        int fa=in();
//        f[i][1]=in();
//        add(fa,i);
//    }
//    dp(0);
//    printf("%d\n",f[0][m+1]);
//    for(int i=0;i<20;i++) {
//        printf("%d %d\n",e[i].to,e[i].pre);
//    }
//    return 0;
//}