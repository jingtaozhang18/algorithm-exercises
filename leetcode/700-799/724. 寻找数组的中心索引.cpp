// https://leetcode-cn.com/problems/find-pivot-index/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int i, size=nums.size();
      for(i=1;i<size;++i) nums[i]+=nums[i-1];
      for(i=0;i<size;++i) if((i>0?nums[i-1]:0)==nums[size-1]-nums[i]) return i;
      return -1;
    }
};