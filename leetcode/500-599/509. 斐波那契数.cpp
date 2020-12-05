// https://leetcode-cn.com/problems/fibonacci-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int N) {
        if(N<=1) return N;
        return fib(N-1)+fib(N-2);
    }
};


class Solution {
public:
    int fib(int N) {
        if(N<=1) return N;
        int a=0, b=1, t, i;
        for(i=2;i<=N;++i) t=a+b, a=b, b=t;
        return b;
    }
};