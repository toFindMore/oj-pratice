//
// Created by 周健 on 2019-09-01.
//
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    int low= 1,high=m*n,mid;
    while(low < high) {
        mid = low+(high-low)/2;
        int count = 0;
        int j = n-1;
        for(int i=0;i<n;i++) {
            while(j>=0&&(i+1)*(j+1) >mid) j--;
            count += j+1;
        }
        if(k >n*m-count) high = mid;
        else low=mid+1;
    }
    cout << low << endl;
    return 0;
}
