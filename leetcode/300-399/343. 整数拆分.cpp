// https://leetcode-cn.com/problems/integer-break/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int ans=1;
        int a = n/3;
        int b = n%3;
        if(b==1) --a, b=4;
        if(b==0) b=1;
        for(int i=0;i<a;++i) ans*=3;
        ans*=b;
        return ans;
    }
};