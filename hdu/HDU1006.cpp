#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX_N = 1 << 17;

int main() {
    //秒针每秒转6度，分针60秒转6度（一分钟），时针3600秒转30度（一个小时）。
    double W_s = 6, W_m = 1.0 / 10.0, W_h = 1.0 / 120.0;//角速度

    //两指针的相对角速度，即分离的速度（相当于物理中的追及问题）
    double W_hs = W_s - W_h;
    double W_hm = W_m - W_h;
    double W_ms = W_s - W_m;

    //两针从重合到再次重合所花的时间。（角速度公式）
    double T_hs = 360.0 / W_hs;
    double T_hm = 360.0 / W_hm;
    double T_ms = 360.0 / W_ms;

    double N = 12.0 * 60.0 * 60.0;//一天的时间，单位为秒

    double n;//输入的度数
    while (scanf("%lf", &n) && n >= 0.0) {
        double ans = 0.0;//表示12*60*60秒中有多少秒符合条件

        //两针分离到n度所需要的时间
        double n_hs1 = n / W_hs;
        double n_hm1 = n / W_hm;
        double n_ms1 = n / W_ms;

        //两针合并到n度时所需要的时间（还差n度就再次重合）
        double n_hs2 = (360.0 - n) / W_hs;
        double n_hm2 = (360.0 - n) / W_hm;
        double n_ms2 = (360.0 - n) / W_ms;

        //每次所有的针从有重合到再次有重合至多有一段连续的段符合三针分离度大于n。
        for (double hs = 0.0; hs <= N; hs += T_hs) {
            for (double hm = 0.0; hm <= N; hm += T_hm) {

                //表示两者没有交集
                if (hm + n_hm2 < hs + n_hs1) continue;//因为hm会随着循环增大
                if (hs + n_hs2 < hm + n_hm1) break;//hs在这个循环中不变，而hm一直在增大，所以break

                for (double ms = 0.0; ms <= N; ms += T_ms) {
                    //同上
                    if (ms + n_ms2 < hs + n_hs1 || ms + n_ms2 < hm + n_hm1) continue;
                    if (hm + n_hm2 < ms + n_ms1 || hs + n_hs2 < ms + n_ms1) break;

                    //在这三个时间段刚好完成分离n度，所以取最大值才能保证全都分离n度以上
                    double res1 = max(max(hs + n_hs1, hm + n_hm1), ms + n_ms1);
                    //在这三个时间段刚好完成合并n度，所以取最小值才能保证全都未合并到n度以内
                    double res2 = min(min(hs + n_hs2, hm + n_hm2), ms + n_ms2);

                    //相当于取res1对应图与res2对应图的交集，只有交集部分才大于n度
                    if (res1 < res2) ans += res2 - res1;
                }
            }
        }
        printf("%.3lf\n", ans / N * 100.0);//所占比例的百分比
    }
    return 0;
}