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