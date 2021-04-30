// https://leetcode-cn.com/problems/single-number-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0, b=0;
        for(auto &e:nums){
            a=(~a&~b&e)|(a&~b&~e);
            b=(~a&~b&e)|(~a&b&~e);
        }
        return (~b)&a;
    }
};