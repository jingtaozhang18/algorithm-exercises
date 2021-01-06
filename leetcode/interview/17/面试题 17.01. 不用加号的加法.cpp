// https://leetcode-cn.com/problems/add-without-plus-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
      int c;
      while(b&&a){ // 小的改进
        c=(unsigned int)(a&b)<<1; // 注意int类型负数左移会报错
        a=a^b;
        b=c;
      }
      return a?a:b;
    }
};