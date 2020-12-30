// https://leetcode-cn.com/problems/one-away-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
      int m=first.size(), n=second.size();
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      int i,j,k;
      // 初始化边界
      for(i=n,k=0;i>=0;--i) dp[m][i]=k++;
      for(i=m,k=0;i>=0;--i) dp[i][n]=k++;
      for(i=m-1;i>=0;--i)
      {
        for(j=n-1;j>=0;--j)
        {
          // 分开写更清楚，还少出错
          dp[i][j]=dp[i+1][j+1];
          if(first[i]!=second[j]) dp[i][j]++;
          dp[i][j]=min({dp[i][j],dp[i][j+1]+1,dp[i+1][j]+1});
        }
      }
      // for(i=0;i<=m;++i)
      // {
      //   for(j=0;j<=n;++j)
      //   {
      //     cout<<dp[i][j]<<" ";
      //   }
      //   cout<<endl;
      // }
      return dp[0][0]<=1;
    }
};