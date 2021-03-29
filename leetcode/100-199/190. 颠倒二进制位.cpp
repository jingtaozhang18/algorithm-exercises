// https://leetcode-cn.com/problems/reverse-bits/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unsigned int m1=0x00ff00ff;
    unsigned int m2=0x0f0f0f0f;
    unsigned int m3=0x33333333;
    unsigned int m4=0x55555555;
    uint32_t reverseBits(uint32_t n) {
        n = (n>>16) | (n<<16);
        n = ((n&m1)<<8) | ((n&~m1)>>8);
        n = ((n&m2)<<4) | ((n&~m2)>>4);
        n = ((n&m3)<<2) | ((n&~m3)>>2);
        n = ((n&m4)<<1) | ((n&~m4)>>1);
        return n;
    }
};