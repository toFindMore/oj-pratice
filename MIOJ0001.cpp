//
// Created by 周健 on 2019-08-18.
//

#include <cstdio>

using namespace std;

int main()
{
    long long a, b;

    while (EOF != scanf("%lld%lld", &a, &b)) {
        printf("%lld\n", a + b);
    }
    return 0;
}