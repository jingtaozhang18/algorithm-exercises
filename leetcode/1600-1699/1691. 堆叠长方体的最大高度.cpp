// https://leetcode-cn.com/problems/maximum-height-by-stacking-cuboids/
#include<bits/stdc++.h>
using namespace std;

// 基础版，参考: 面试题 08.13. 堆箱子
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
      int size=cuboids.size(),i,j,ans=0;
      for(i=0;i<cuboids.size();++i) sort(cuboids[i].begin(), cuboids[i].end());
      sort(cuboids.begin(),cuboids.end());
      vector<int> dp(size, 0);
      for(i=0;i<size;++i)
      {
        for(j=0;j<i;++j)
        {
          if(cuboids[j][0]<=cuboids[i][0]&&cuboids[j][1]<=cuboids[i][1]&&cuboids[j][2]<=cuboids[i][2])
          {
            dp[i]=max(dp[i], dp[j]);
          }
        }
        dp[i]+=cuboids[i][2];
        ans=max(dp[i], ans);
      }
      return ans;
    }
};