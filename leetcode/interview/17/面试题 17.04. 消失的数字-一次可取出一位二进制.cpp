// https://leetcode-cn.com/problems/missing-number-lcci/
#include<bits/stdc++.h>
using namespace std;

// 一次可以取出一个完整整数
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sum=0, size=nums.size();
      for(auto e:nums) sum+=e;
      return size*(size+1)/2-sum;
    }
};