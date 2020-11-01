// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        int a=1,b=1,c=0;
        if(n==0)return a;
        if(n==1)return b;
        n-=1;
        while(n--) c=(a+b)%1000000007,a=b,b=c;
        return c;
    }
};