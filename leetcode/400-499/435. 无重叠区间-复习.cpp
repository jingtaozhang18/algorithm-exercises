// https://leetcode-cn.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jfind(vector<int>& dp, int right, int target){ // 找到第一个比target大于的位置
      int center;
      int left=0;
      while(left<=right)
      {
        center=(left+right)>>1;
        if(dp[center]>target) right=center-1;
        else left=center+1;
      }
      return left;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int size=intervals.size();
      sort(intervals.begin(), intervals.end());
      vector<int> dp(size, INT_MAX);
      int right=-1,i,pos;
      for(i=0;i<size;++i)
      {
        pos=jfind(dp, right, intervals[i][0]);
        right=max(right, pos);
        dp[pos]=min(dp[pos], intervals[i][1]);
      }
      return size-right-1;
    }
};