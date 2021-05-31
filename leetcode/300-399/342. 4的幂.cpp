// https://leetcode-cn.com/problems/power-of-four/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0&&!(n&(n-1))&&(n&0x55555555);
    }
};