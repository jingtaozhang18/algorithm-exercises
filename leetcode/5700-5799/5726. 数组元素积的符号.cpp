// https://leetcode-cn.com/contest/weekly-contest-236/problems/sign-of-the-product-of-an-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num=0;
        for(auto &e:nums){
            if(e<0) num++;
            else if(e==0) return 0;
        }
        if(num%2==0) return 1;
        else return -1;
    }
};