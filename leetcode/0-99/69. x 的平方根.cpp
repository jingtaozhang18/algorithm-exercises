// https://leetcode-cn.com/problems/sqrtx/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0; // 防止除0
        double c=x, x0=x; // 从x开始初始化，防止找到了负数
        while(true){
            double xi = 0.5 * (x0 + c / x0); // 导数的斜线与x轴的交点;除法需要进行判断
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};