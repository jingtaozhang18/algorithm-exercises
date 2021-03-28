// https://leetcode-cn.com/problems/powx-n/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool flag = false;
        double o;
        if(n==INT_MIN) { // 错误点 最小值 加负号
            n+=1, n=-n, x=1/x, o=x, flag=true;
        }else{
            if(n<0) n=-n, x=1/x;
        }
        double ans=1;
        while(n){
            if(n&0x00000001) ans*=x;
            x*=x;
            n>>=1;
        }
        if(flag) ans*=o;
        return ans;
    }
};