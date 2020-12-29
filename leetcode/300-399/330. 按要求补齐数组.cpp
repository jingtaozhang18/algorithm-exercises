// https://leetcode-cn.com/problems/patching-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
      int need=0,i=0; long long x=1;
      // x当前无法覆盖的第一个数字，再吸纳了一个新的小于等于x的数字a之后，根据递推规律，会覆盖到x+a-1, 下一个待覆盖的数字是x+a; 
      // 注意x会乘2,注意数组越界问题
      while(x<=n){
        if(i<nums.size()&&nums[i]<=x) x+=nums[i], ++i;
        else ++need, x<<=1;
      }
      return need;
    }
};