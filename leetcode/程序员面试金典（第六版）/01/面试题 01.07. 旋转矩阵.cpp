// https://leetcode-cn.com/problems/rotate-matrix-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int o,m=matrix.size(),i,t;
      for(o=0;o<(m>>1);++o)
      {
        for(i=o;i<m-o-1;++i)
        {
          t=matrix[o][i];
          matrix[o][i]=matrix[m-i-1][o];
          matrix[m-i-1][o]=matrix[m-o-1][m-1-i];
          matrix[m-o-1][m-1-i]=matrix[i][m-o-1];
          matrix[i][m-o-1]=t;
        }
      }
    }
};