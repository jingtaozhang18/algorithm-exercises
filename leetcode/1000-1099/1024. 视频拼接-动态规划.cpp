// https://leetcode-cn.com/problems/video-stitching/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
      int i, size=clips.size();
      vector<int> dp(T+1, INT_MAX-10); // dp[i], [0, T]需要的最少视频段
      dp[0]=0;
      for(i=1;i<=T;++i){
        for(auto av:clips){
          if(av[0]<i&&av[1]>=i){
            dp[i]=min(dp[i], dp[av[0]]+1);
          }
        }
      }
      return (dp[T]==INT_MAX-10)?-1:dp[T];
    }
};