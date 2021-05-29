// https://leetcode-cn.com/problems/total-hamming-distance/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
      unsigned int flag;
      int acc[32], ans=0, n=nums.size(), i, j;
      for(i=0;i<32;++i) acc[i]=0;
      for(i=0;i<n;++i)
        for(j=0,flag=1;j<32;++j,flag<<=1)
          if(flag&nums[i]) acc[j]++;
      for(i=0;i<32;++i) ans+=acc[i]*(n-acc[i]);
      return ans;
    }
};