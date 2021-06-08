// https://leetcode-cn.com/problems/divide-two-integers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long jgo(long long a, long long b){
        if(a<b) return 0;
        long long count=1, bb=b;
        while(bb+bb<=a){
            count=count+count;
            bb=bb+bb;
        }
        return count+jgo(a-bb, b);
    }
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if(divisor==-1) return dividend==INT_MIN?INT_MAX:-dividend;
        bool sign=(dividend>0&&divisor>0)||(dividend<0&&divisor<0);
        dividend=abs(dividend), divisor=abs(divisor);
        return sign?jgo(dividend, divisor):-jgo(dividend, divisor);
    }
};