// https://leetcode-cn.com/problems/re-space-lcci/
#include<bits/stdc++.h>
using namespace std;

// 最多的错误就是数值越界的问题
class Solution {
public:
    long long jgo(long long val, long long t){
      return ((long long)val-INT_MIN) / (t+1);
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long long, int> mp;
        int i; long long x, y;
        for(i=0;i<nums.size();++i){
          y=nums[i], x=jgo(y, t);
          if(mp.count(x)) return true;
          if(mp.count(x-1)&&abs(y-mp[x-1])<=t) return true;
          if(mp.count(x+1)&&abs(y-mp[x+1])<=t) return true;
          mp[x]=y;
          if(i>=k){
            x=jgo(nums[i-k], t);
            mp.erase(x);
          }
        }
        return false;
    }
};