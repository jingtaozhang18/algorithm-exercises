// https://leetcode-cn.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int i,j,m=grid.size(),n=grid[0].size(),t;
      for(i=0;i<m;++i){
        for(j=0;j<n;++j){
          if(i==0&&j==0) continue;
          t=INT_MAX;
          if(i>0) t=min(t, grid[i-1][j]);
          if(j>0) t=min(t, grid[i][j-1]);
          grid[i][j]+=t;
        }
      }
      return grid[m-1][n-1];
    }
};