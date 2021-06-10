// https://leetcode-cn.com/problems/coin-change-2/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unordered_set<int> st(coins.begin(), coins.end());
        coins = vector<int>(st.begin(), st.end());
        int m=coins.size(), i, j, k;
        int dp[m+1][amount+1]; // dp[i][j] 前i种硬币，拼成j的数值的方案数
        for(i=0;i<=m;++i)for(j=0;j<=amount;++j) dp[i][j]=j==0?1:0;
        for(i=0;i<m;++i){ // 方案数
            for(j=1;j<=amount;++j){ // 金额
                for(k=0;j-coins[i]*k>=0;++k){ // 当前硬币数量
                    dp[i+1][j]+=dp[i][j-coins[i]*k];
                }
            }
        }
        return dp[m][amount];
    }
};