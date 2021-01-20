// https://leetcode-cn.com/problems/move-zeroes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size(), i=0, j=0;
        for(;i<size;++i) {
          if(nums[i]!=0) swap(nums[i], nums[j++]);
        }
    }
};