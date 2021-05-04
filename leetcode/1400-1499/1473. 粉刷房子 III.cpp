// https://leetcode-cn.com/problems/paint-house-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
      int dp[m+1][n][target+1], i, j, k, pj, x; // dp[i][j][k] 粉刷到第i个房子（编号i-1）时，涂颜色j+1时共有k个街区的最小开销
      // 初始化
      for(j=0;j<n;++j){
        for(k=0;k<=target;++k){
          if(k==0) dp[0][j][k]=0;
          else dp[0][j][k]=INT_MAX;
        }
      }
      for(i=1;i<=m;++i){
        for(j=0;j<n;++j){
          dp[i][j][0]=INT_MAX; // 错误点，数组中每个位置都需要赋值
          for(k=1;k<=target;++k){
            dp[i][j][k]=INT_MAX;
            if(houses[i-1]!=0){ // 已经被涂上了颜色
              if(houses[i-1]-1!=j) continue;
              for(x=INT_MAX,pj=0;pj<n;++pj){
                if(pj!=houses[i-1]-1) x=min(x, dp[i-1][pj][k-1]);
                else x=min(x, dp[i-1][pj][k]);
              }
              dp[i][j][k]=x;
            }else{
              for(x=INT_MAX,pj=0;pj<n;++pj){
                if(pj!=j) x=min(x, dp[i-1][pj][k-1]);
                else x=min(x, dp[i-1][pj][k]);
              }
              if(x==INT_MAX) continue;
              else dp[i][j][k]=x+cost[i-1][j];
            }
          }
        }
      }
      for(x=INT_MAX, j=0;j<n;++j){
        x=min(x, dp[m][j][target]);
      }
      return x==INT_MAX?-1:x;
    }
};