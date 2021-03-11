// https://leetcode-cn.com/problems/continuous-subarray-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int acc=0;
      unordered_map<int, int> mp;
      mp[0]=-1;
      for(int i=0;i<nums.size();++i){ // 取余数之后， [0, i]和[0, j]和之模相等，就表示都是k的倍数，这个范围内的区间和还是k的倍数
        acc+=nums[i];
        if(k) acc=acc%k;
        if(mp.find(acc)!=mp.end()) {
          if(i-mp[acc]>1) return true; // 错误点，需要记录数组的长度满足要求才可以，0是比较特殊的情况
        }else{
          mp[acc]=i;
        }
      }
      return false;
    }
};