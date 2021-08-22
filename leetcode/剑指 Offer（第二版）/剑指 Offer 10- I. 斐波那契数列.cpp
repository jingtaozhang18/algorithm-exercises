// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int a=0,b=1,c=1;
        n-=1;
        while(n--){
            c=(a+b)%1000000007,a=b,b=c;
        }
        return c;
    }
};

class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int a=0, b=1, c, m=1e9+7;
        n-=1;
        while(n--) c=(a+b)%m, a=b, b=c;
        return c;
    }
};