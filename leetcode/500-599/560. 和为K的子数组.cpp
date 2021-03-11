// https://leetcode-cn.com/problems/subarray-sum-equals-k/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> map; // 前缀和，出现的次数
      unordered_map<int, int>::iterator p;
      map[0]++;
      int acc=0, ans=0;
      for(int i=0;i<nums.size();++i){
        acc+=nums[i];
        if((p=map.find(acc-k))!=map.end()) ans+=p->second;
        map[acc]++;
      }
      return ans;
    }
};