// https://leetcode-cn.com/problems/stone-game-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
      int i, j, t, n=stoneValue.size();
      vector<int> dp(n+1, INT_MIN);
      dp[n]=0; // 先手可以领先的分数
      for(i=n-1;i>=0;--i){
        for(j=i,t=0;j<min(n, i+3);++j){
          t+=stoneValue[j];
          dp[i]=max(dp[i], t-dp[j+1]);
        }
      }
      if(dp[0]>0) {
        return "Alice";
      } else if(dp[0]==0){
        return "Tie";
      } else{
        return "Bob";
      }
    }
};