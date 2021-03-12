// https://leetcode-cn.com/problems/edit-distance/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i, j, k, m=word1.size(), n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // 初始化边界
        for(i=m,k=0;i>=0;--i) dp[i][n]=k++;
        for(i=n,k=0;i>=0;--i) dp[m][i]=k++;
        for(i=m-1;i>=0;--i){
            for(j=n-1;j>=0;--j){
                if(word1[i]==word2[j]) dp[i][j]=dp[i+1][j+1];
                else dp[i][j]=dp[i+1][j+1]+1;
                dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
            }
        }
        return dp[0][0];
    }
};