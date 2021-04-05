// https://leetcode-cn.com/problems/longest-common-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size(),i,j,ans=0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(text1[i]==text2[j]) dp[i][j]=((i>0&&j>0)?dp[i-1][j-1]:0)+1;
                else dp[i][j]=max(i>0?dp[i-1][j]:0, j>0?dp[i][j-1]:0);
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

// 复习
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
            int m=text1.size(), n=text2.size(), i, j;
            int dp[m+1][n+1];
            for(i=0;i<=m;++i) for(j=0;j<=n;++j) dp[i][j]=0;
            for(i=1;i<=m;++i){
                for(j=1;j<=n;++j){
                    if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                    else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
            return dp[m][n];
    }
};