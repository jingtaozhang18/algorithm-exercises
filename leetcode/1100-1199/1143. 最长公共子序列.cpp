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