// https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        int t=1;
        while(b){
            t=(unsigned int)(a&b)<<1,a=a^b,b=t; // C++ 不支持负值左移
        }
        return a;
    }
};