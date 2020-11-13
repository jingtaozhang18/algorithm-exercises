// https://leetcode-cn.com/problems/number-of-digit-one/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long jgo(long long a, long long b){
        if(a<b)b=a;
        if(b<0)b=0;
        return b;
    }
    // 遍历每一位中1出现的次数
    int countDigitOne(int n) {
        if(n<=0) return 0;
        long long  t=1, a=n, ans=0; // t组中元素的数量, a记录位数, t/10一组内出现1的最大数量
        while(a)  {
            a/=10, t*=10, ans+=(n/t)*(t/10), ans+=jgo(t/10, n%t-t/10+1);}
        return ans;
    }
};