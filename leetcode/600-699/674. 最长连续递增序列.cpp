// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i,j,size=nums.size(),ans=1;
        if(!size) return 0;
        vector<int> dp(size);
        dp[0]=1;
        for(i=1;i<size;++i){
            dp[i]=nums[i]>nums[i-1]?dp[i-1]+1:1;
            ans=max(dp[i], ans);
        }
        return ans;
    }
};

// 每日一题 复习
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      int i, ans=0, size=nums.size();
      if(size==0) return ans;
      vector<int> arr(size);
      for(i=1;i<size;++i){
        if(nums[i]>nums[i-1]) arr[i]=arr[i-1]+1;
        ans=max(ans, arr[i]);
      }
      return ++ans;
    }
};