// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> mem(nums.size(), false);
        for(int i=0;i<nums.size();++i){
            if(mem[nums[i]]) return nums[i];
            mem[nums[i]]=true;
        }
        return -1;
    }
};