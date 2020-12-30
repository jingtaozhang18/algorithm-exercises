// https://leetcode-cn.com/problems/max-submatrix-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
      int m=matrix.size(), n=matrix[0].size(),i,j,k,tamax=INT_MIN,amax=INT_MIN, aidx;
      vector<int> acc(n, 0); // 行压缩之后的累加和
      vector<int> dp(n, 0); // 动态规划
      vector<int> idx(n, 0); // 记录起点
      vector<int> ans(4, 0); // 答案
      idx[0]=0;
      for(i=0;i<m;++i){
        for(k=0;k<n;++k) acc[k]=0;
        for(j=i;j<m;++j){
          for(k=0;k<n;++k) 
            acc[k]+=matrix[j][k]; // [i,j]行之间累加
          for(k=0;k<n;++k){ // 错误点: 要从0开始看，因为里面包含和amax的比较
            if(k>0&&dp[k-1]>0) dp[k]=dp[k-1]+acc[k], idx[k]=idx[k-1];
            else dp[k]=acc[k],idx[k]=k;
            if(dp[k]>amax) aidx=k,amax=dp[k]; // aidx记录了当前最大值对应的下标
          }
          if(amax>tamax) tamax=amax, ans[0]=i, ans[1]=idx[aidx], ans[2]=j, ans[3]=aidx;
        }
      }
      return ans;
    }
};