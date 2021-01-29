// https://leetcode-cn.com/problems/path-with-minimum-effort/
#include<bits/stdc++.h>
using namespace std;

// 暴力更新
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int i,j,m=heights.size(),n=heights[0].size(),x,y,a,b,newd;
      vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
      dp[0][0]=0;
      int dir[4][2]{-1,0,1,0,0,1,0,-1};
      queue<pair<int, int>> que;
      que.push(make_pair(0,0));
      while(!que.empty()){
        a=que.front().first;
        b=que.front().second;
        que.pop();
        for(i=0;i<4;++i){
          x=a+dir[i][0];
          y=b+dir[i][1];
          if(x>=0&&x<m&&y>=0&&y<n){ // 合法
            newd=max(dp[a][b], abs(heights[a][b]-heights[x][y]));
            if(newd<dp[x][y]){
              dp[x][y]=newd;
              que.push(make_pair(x,y));
            }
          }
        }
      }
      return dp[m-1][n-1];
    }
};