// https://leetcode-cn.com/problems/path-with-minimum-effort/
#include<bits/stdc++.h>
using namespace std;

// dijkstra思想借鉴出来的
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int i,j,m=heights.size(),n=heights[0].size(),x,y,a,b,d,newd;
      vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
      dp[0][0]=0;
      int dir[4][2]{-1,0,1,0,0,1,0,-1};
      auto tupleCmp = [](const auto &e1, const auto &e2){
            auto&& [x1, y1, d1] = e1;
            auto&& [x2, y2, d2] = e2;
            return d1 > d2;
      };
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> que(tupleCmp);
      que.emplace(0, 0, 0);
      while(!que.empty()){
        auto t = que.top();
        a=get<0>(t), b=get<1>(t), d=get<2>(t);
        que.pop();
        if(d>dp[a][b]) continue;
        for(i=0;i<4;++i){
          x=a+dir[i][0];
          y=b+dir[i][1];
          if(x>=0&&x<m&&y>=0&&y<n){ // 合法
            newd=max(dp[a][b], abs(heights[a][b]-heights[x][y]));
            if(newd<dp[x][y]){
              dp[x][y]=newd;
              que.emplace(x,y,newd);
            }
          }
        }
      }
      return dp[m-1][n-1];
    }
};