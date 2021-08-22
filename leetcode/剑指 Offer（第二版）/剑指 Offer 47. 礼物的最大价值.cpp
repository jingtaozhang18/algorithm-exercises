// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int i,j,k,row=grid.size(),col=grid[0].size();
        for(i=1;i<col;++i) grid[0][i]+=grid[0][i-1];
        for(i=1;i<row;++i) grid[i][0]+=grid[i-1][0];
        for(i=1;i<row;++i){
            for(j=1;j<col;++j){
                grid[i][j]+=max(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};

// 复习
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
      int i, j, x, m=grid.size(), n=m==0?0:grid[0].size();
      if(m==0||n==0) return 0;
      for(i=0;i<m;++i){
        for(j=0;j<n;++j){
          x=0;
          if(i)x=max(x, grid[i-1][j]);
          if(j)x=max(x, grid[i][j-1]);
          grid[i][j]+=x;
        }
      }
      return grid[m-1][n-1];
    }
};