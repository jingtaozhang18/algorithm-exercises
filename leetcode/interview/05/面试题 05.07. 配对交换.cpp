// https://leetcode-cn.com/problems/exchange-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int exchangeBits(int num) {
        return ((num&0xaaaaaaaa)>>1) | ((num&0x55555555)<<1);
    }
};