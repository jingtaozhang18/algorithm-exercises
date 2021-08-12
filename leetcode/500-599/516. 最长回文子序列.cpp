// https://leetcode-cn.com/problems/longest-palindromic-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size=s.size(), i, j, diff;
        // vector<vector<int>>dp(size, vector<int>(size, 0));
        short dp[size][size]; // 优化
        for(diff=0;diff<size;++diff){
            for(i=0;i<size-diff;++i){
                j=i+diff;
                if(diff==0) dp[i][j]=1;
                else if(diff==1) dp[i][j]=s[i]==s[j]?2:1;
                else{
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                    // dp[i][j]=max({dp[i+1][j], dp[i][j], dp[i][j-1]});
                    else dp[i][j]=max({dp[i+1][j], dp[i][j-1]}); // 优化
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[0][size-1];
    }
};

// 复习
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size(), i, j, k;
        vector<vector<int>> dp(m, vector<int>(m));
        for(k=0;k<m;++k){
            for(i=0;i<m-k;++i){
                j=i+k;
                if(s[i]==s[j]){
                    if(i==j) dp[i][j]=1;
                    else dp[i][j]=dp[i+1][j-1]+2;
                }
                else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][m-1];
    }
};
