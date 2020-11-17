// https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,INT_MAX));
        int i,j,k,a,b,cost;
        for(i=0;i<=n;++i)dp[i][i]=0;
        for(i=1;i<=n;++i){ // 斜对角线遍历
            for(j=1;j+i<=n;++j){
                a=j, b=j+i;
                for(k=a;k<=b;++k) {
                    cost=k+max(k==a?0:dp[a][k-1], k==b?0:dp[k+1][b]);
                    dp[a][b]=min(dp[a][b], cost);
                }
            }
        }
        return dp[1][n];
    }
};