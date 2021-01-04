// https://leetcode-cn.com/problems/dungeon-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      // 会进入局部最优解
      int m=dungeon.size(), n=dungeon[0].size();
      vector<vector<int>> need(m, vector<int>(n, INT_MAX));
      vector<vector<int>> left(m, vector<int>(n));
      int i,j,t;
      for(i=0;i<m;++i){
        for(j=0;j<n;++j){
          if(i==0&&j==0){
            need[i][j]=max(1, 1-dungeon[i][j]);
            left[i][j]=need[i][j]+dungeon[i][j];
          }else{
            if(i>0){
              if(need[i][j]>(t=need[i-1][j]+max(0,1-left[i-1][j]-dungeon[i][j]))){
                need[i][j]=t;
                left[i][j]=left[i-1][j]+max(0,1-left[i-1][j]-dungeon[i][j])+dungeon[i][j];
              }
            }
            if(j>0){
              if(need[i][j]>(t=need[i][j-1]+max(0,1-left[i][j-1]-dungeon[i][j]))){
                need[i][j]=t;
                left[i][j]=left[i][j-1]+max(0,1-left[i][j-1]-dungeon[i][j])+dungeon[i][j];
              }
            }
          }
        }
      }
      return need[m-1][n-1];
    }
};
