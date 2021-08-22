// https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n==0) return 0;
        long long start=1, num=9, digit=1, t=n-1, a, b; // 去掉前面n-1个数
        while(t>=num) t-=num, start*=10, digit++, num=9*start*digit;
        a=t/digit, b=digit-(t%digit)-1, start=start+a;
        while(b--) start/=10;
        return start%10;
    }
};

// 复习
class Solution {
public:
    int findNthDigit(int n) {
      if(n==0) return 0;
      long long nums=9, i=1; // i位长度的数字有nums个 注意边界范围
      while(n-nums*i>0) n-=nums*i, nums*=10, ++i;
      // 落在了长度为i的数值中的第n位
      --n; // 从0开始编号
      int x=n/i; // if(x%i) ++x; // 长度为i的数字中的第x位数字
      int y=i-1-n%i; // 目标数字中的第y个值
      x=pow(10, i-1)+x;
      while(y--){
        x/=10;
      }
      return x%10;
    }
};