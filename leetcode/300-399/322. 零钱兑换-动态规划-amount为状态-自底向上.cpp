// https://leetcode-cn.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        int i, j;
        for(i=1;i<=amount;++i){
            for(auto c:coins){
                if(i-c<0) continue;
                dp[i]=min(dp[i], 1+dp[i-c]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};