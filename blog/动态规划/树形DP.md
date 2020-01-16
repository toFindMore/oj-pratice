# 树形DP
## 一些场景
数据分布是树形结构，往往根据子节点信息推出父节点最优条件。

树形DP有多种变形：如多叉树情况下，假设前n个字节点已经算出，求第n+1个字节需要拿出多少资源

dp(i,j)表示i号节点拥有j资源时的最值

可以参看本项目中关于树形DP的练习题 
- [专项训练](https://github.com/toFindMore/OJ_Practice/tree/master/special-practice/%E6%A0%91%E5%BD%A2DP)
- 题目合集
    - [HDU1011 Starship Troopers](https://github.com/toFindMore/OJ_Practice/blob/master/hdu/HDU1011.cpp)
- [相关博客]
    - [树形DP](https://github.com/toFindMore/OJ_Practice/blob/master/blog/%E5%9B%BE/%E6%A0%91%E7%9A%84%E7%9B%B4%E5%BE%84.md)