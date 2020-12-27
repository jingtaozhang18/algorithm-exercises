// https://leetcode-cn.com/problems/where-will-the-ball-fall/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
      int m=grid.size(), n=grid[0].size(), i,j,t;
      vector<int> ans(n, -1);
      for(i=0;i<n;++i){ // 第i列的球, t表示当前位置
        for(t=i,j=0;j<m;++j){
          if(grid[j][t]==1&&t+1<n&&grid[j][t+1]==1){ // 向右不卡球
            t++;
          }else if(grid[j][t]==-1&&t>0&&grid[j][t-1]==-1){ // 向左不卡球
            t--;
          }else{
            break;
          }
        }
        if(j==m) ans[i]=t;
      }
      return ans;
    }
};