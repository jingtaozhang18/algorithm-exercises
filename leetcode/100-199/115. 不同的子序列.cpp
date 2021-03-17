// https://leetcode-cn.com/problems/distinct-subsequences/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int i,j,m=s.size(), n=t.size();
        long long dp[n+1][m+1];  // 错误点， 实现的时候，数组和思路写反了； 题目中保证答案不会越界， 不代表中间结果不会越界
        // 初始化DP数组  dp[i][j]表示 s[0:j]子序列中为t[0:i]的数量
        for(i=0;i<=n;++i){
            for(j=0;j<=m;++j){
                if(i==0) dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        for(i=1;i<=n;++i){
            for(j=i;j<=m;++j){
                if(t[i-1]==s[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                dp[i][j] += dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};