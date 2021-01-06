// https://leetcode-cn.com/problems/number-of-islands/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mem;
    int jfind(int i){
      if(mem[i]==i) return i;
      return mem[i]=jfind(mem[i]);
    }

    void jmerge(int i, int j){
      i=jfind(i);
      j=jfind(j);
      mem[i]=j;
    }

    int numIslands(vector<vector<char>>& grid) {
      int m=grid.size(), n=grid[0].size(),i,j;
      mem=vector<int>(m*n);
      for(i=0;i<m*n;++i) mem[i]=i;
      for(i=0;i<m;++i){
        for(j=0;j<n;++j){
          if(grid[i][j]=='1'){
            if(i>0&&grid[i-1][j]=='1') jmerge((i-1)*n+j, i*n+j);
            if(j>0&&grid[i][j-1]=='1') jmerge(i*n+j-1, i*n+j);
          }
        }
      }
      set<int> st;
      for(i=0;i<m;++i){
        for(j=0;j<n;++j){
          if(grid[i][j]=='1'){
            st.insert(jfind(i*n+j));
          }
        }
      }
      return st.size();
    }
};