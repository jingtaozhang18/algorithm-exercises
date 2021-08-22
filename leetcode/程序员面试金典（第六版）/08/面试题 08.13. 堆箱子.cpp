// https://leetcode-cn.com/problems/pile-box-lcci/
#include<bits/stdc++.h>
using namespace std;

// 进阶版，参考: 1691. 堆叠长方体的最大高度
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
      int i,j,maxl,ans=0,size=box.size();
      sort(box.begin(), box.end());
      // 动态规划
      vector<int> dp(size, 0);  // 是顶的时候，最大高度.
      for(i=0;i<size;++i)
      {
        maxl=0;
        for(j=0;j<i;++j)
        {
          if(box[i][0]>box[j][0]&&box[i][1]>box[j][1]&&box[i][2]>box[j][2])
          {
            maxl=max(maxl, dp[j]);
          }
        }
        dp[i]=maxl+box[i][2];
        ans=max(ans, dp[i]);
      }
      return ans;
    }
};