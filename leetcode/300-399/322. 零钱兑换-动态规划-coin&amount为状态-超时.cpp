// https://leetcode-cn.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size=coins.size(),i,j,ans=INT_MAX;
        long long k, t; // 错误点 数值范围
        vector<vector<int>> dp(size, vector<int>(amount+1, INT_MAX));
        for(i=0;i<size;++i){
            if(i==0){
                for(j=0;(t=coins[i]*j)<=amount;++j){
                    dp[i][t]=j;
                    if(t==amount) ans=min(j, ans);
                }
            }else{
                for(k=0;k<=amount;++k){
                    if(dp[i-1][k]==INT_MAX) continue;
                    for(j=0;(t=k+coins[i]*j)<=amount;++j){
                        dp[i][t]=min(dp[i][t], j+dp[i-1][k]);
                        if(t==amount) ans=min(ans, dp[i][t]);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};