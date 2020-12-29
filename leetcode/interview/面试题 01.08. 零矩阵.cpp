// https://leetcode-cn.com/problems/zero-matrix-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      set<int> row;
      set<int> col;
      int i,j,m=matrix.size(),n=matrix[0].size();
      for(i=0;i<m;++i)
      {
        for(j=0;j<n;++j)
        {
          if(matrix[i][j]==0)
          {
            row.insert(i);
            col.insert(j);
          }
        }
      }
      for(i=0;i<m;++i)
      {
        for(j=0;j<n;++j)
        {
          if(row.find(i)!=row.end()||col.find(j)!=col.end())
          {
            matrix[i][j]=0;
          }
        }
      }
    }
};