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

// 复习
class Solution {
public:
    double myPow(double x, int n) {
        bool flag=false;
        double ans=1, ox=x;
        if(n<0) {
            x=1/x;
            if(n==INT_MIN) n=INT_MAX, flag=true;
            else n=-n;
        }
        while(n){
            if(n&0x00000001){
                ans *= x;
            }
            x*=x;
            n>>=1;
        }
        if(flag) ans*=ox;
        return ans;
    }
};