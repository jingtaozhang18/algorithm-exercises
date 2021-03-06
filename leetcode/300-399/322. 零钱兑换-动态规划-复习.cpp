// https://leetcode-cn.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i, j, k, x, n=coins.size();
        vector<int> dp(amount+1, -1); // 以amount为状态
        dp[0]=0;
        for(i=1;i<=amount;++i){
            x=INT_MAX;
            for(j=0;j<n;++j){
                if((k=i-coins[j])>=0&&dp[k]!=-1) x=min(x, dp[k]);
                if(x!=INT_MAX) dp[i]=x+1;
            }
        }
        return dp[amount];
    }
};