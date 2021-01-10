// https://leetcode-cn.com/problems/summary-ranges/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> ans;
      int a, i, size=nums.size();
      if(size==0) return ans;
      sort(nums.begin(), nums.end());
      for(a=nums[0],i=1;i<=size;++i){
        if(i==size||nums[i-1]+1!=nums[i]){
          if(a==nums[i-1]) ans.push_back(to_string(a));
          else ans.push_back(to_string(a)+"->"+to_string(nums[i-1]));
          if(i<size) a=nums[i];
        }
      }
      return ans;
    }
};