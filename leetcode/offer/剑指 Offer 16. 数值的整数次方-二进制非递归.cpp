// https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool flag;
        double ans=1;
        long long ln=n;
        if(ln>0) flag=true; else flag=false, ln*=-1;
        while(ln){
            if(ln&1) ans*=x;
            x*=x,ln>>=1;
        }
        return flag?ans:1/ans;
    }
};