// https://leetcode-cn.com/problems/n-th-tribonacci-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        n-=2;
        int a=0, b=1, c=1, d;
        while(n--){
            d=a+b+c;
            a=b, b=c, c=d;
        }
        return c;
    }
};
