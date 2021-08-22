// https://leetcode-cn.com/problems/three-steps-problem-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        int a=1,b=2,c=4,i,d;
        if(n==1) return a;
        if(n==2) return b;
        if(n==3) return c;
        for(i=4;i<=n;++i) d=((a+b)%1000000007+c)%1000000007, a=b, b=c, c=d;
        return c;
    }
};