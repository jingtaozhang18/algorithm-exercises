// https://leetcode-cn.com/problems/profitable-schemes/
#include<bits/stdc++.h>
using namespace std;

// 背包问题，和阿里的一道笔试题类似
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size(), i, j, k, x, mod=1e9+7;
        int dp[m+1][n+1][minProfit+1];
        for(i=0;i<=m;++i)for(j=0;j<=n;++j)for(k=0;k<=minProfit;++k) dp[i][j][k]=k==0?1:0;
        for(i=0;i<m;++i){ // 项目
            for(j=0;j<=n;++j){ // 工人数量
                for(k=0;k<=minProfit;++k){ // 盈利
                    dp[i+1][j][k]=dp[i][j][k];
                    if(j>=group[i]&&k>=profit[i])
                        dp[i+1][j][k]+=dp[i][j-group[i]][k-profit[i]], dp[i+1][j][k]%=mod;
                    if(k==minProfit){
                        if(j>=group[i]){
                            for(x=max(0, k-profit[i]+1);x<=minProfit;++x){
                                dp[i+1][j][k]+=dp[i][j-group[i]][x], dp[i+1][j][k]%=mod;
                            }
                        }
                    }
                }
            }
        }
        return dp[m][n][minProfit];
    }
};